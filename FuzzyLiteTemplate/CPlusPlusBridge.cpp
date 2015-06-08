//
//  CPlusPlusBridge.cpp
//  FuzzyLiteTemplate
//
//  Created by Abhishek Sen on 6/8/15.
//  Copyright (c) 2015 Abhi. All rights reserved.
//

#include "CPlusPlusBridge.h"
#include <stdio.h>
#include "fuzzylite/fl/Headers.h"
using namespace fl;

class CPlusPlusBridge {
private:
  void setupSimpleDimmerEngine();
  
public:
  Engine* simpleDimmerEngine = NULL;
  CPlusPlusBridge();
  ~CPlusPlusBridge();
  double process_input_data(double input);
};

CPlusPlusBridge::CPlusPlusBridge() {
  setupSimpleDimmerEngine();
}

CPlusPlusBridge::~CPlusPlusBridge() {
  delete simpleDimmerEngine;
}

void CPlusPlusBridge::setupSimpleDimmerEngine() {
  simpleDimmerEngine = new fl::Engine;
  fl::Engine *engine = simpleDimmerEngine;
  engine->setName("simple-dimmer");

  InputVariable* inputVariable = new InputVariable;
  inputVariable->setEnabled(true);
  inputVariable->setName("Ambient");
  inputVariable->setRange(0.000, 1.000);
  inputVariable->addTerm(new Triangle("DARK", 0.000, 0.250, 0.500));
  inputVariable->addTerm(new Triangle("MEDIUM", 0.250, 0.500, 0.750));
  inputVariable->addTerm(new Triangle("BRIGHT", 0.500, 0.750, 1.000));
  engine->addInputVariable(inputVariable);

  OutputVariable* outputVariable = new OutputVariable;
  outputVariable->setEnabled(true);
  outputVariable->setName("Power");
  outputVariable->setRange(0.000, 2.000);
  outputVariable->fuzzyOutput()->setAccumulation(new Maximum);
  outputVariable->setDefuzzifier(new Centroid(200));
  outputVariable->setDefaultValue(fl::nan);
  outputVariable->setLockPreviousOutputValue(false);
  outputVariable->setLockOutputValueInRange(false);
  outputVariable->addTerm(new Triangle("LOW", 0.000, 0.500, 1.000));
  outputVariable->addTerm(new Triangle("MEDIUM", 0.500, 1.000, 1.500));
  outputVariable->addTerm(new Triangle("HIGH", 1.000, 1.500, 2.000));
  engine->addOutputVariable(outputVariable);

  RuleBlock* ruleBlock = new RuleBlock;
  ruleBlock->setEnabled(true);
  ruleBlock->setName("");
  ruleBlock->setConjunction(0);
  ruleBlock->setDisjunction(0);
  ruleBlock->setActivation(new Minimum);
  ruleBlock->addRule(fl::Rule::parse("if Ambient is DARK then Power is HIGH", engine));
  ruleBlock->addRule(fl::Rule::parse("if Ambient is MEDIUM then Power is MEDIUM", engine));
  ruleBlock->addRule(fl::Rule::parse("if Ambient is BRIGHT then Power is LOW", engine));
  engine->addRuleBlock(ruleBlock);
}

double process_input_data(double ambient) {
  CPlusPlusBridge *bridge = new CPlusPlusBridge();
  double result = 0;
  bridge->simpleDimmerEngine->getInputVariable("Ambient")->setInputValue(ambient);
  bridge->simpleDimmerEngine->process();
  result = bridge->simpleDimmerEngine->getOutputValue("Power");
  return result;
}

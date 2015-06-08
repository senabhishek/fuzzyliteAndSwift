//
//  ViewController.swift
//  FuzzyLiteTemplate
//
//  Created by Abhishek Sen on 6/8/15.
//  Copyright (c) 2015 Abhi. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

  @IBOutlet weak var ambientSlider: UISlider!
  @IBOutlet weak var outputPowerLabel: UILabel!
  
  @IBAction func sliderValueChanged(sender: AnyObject) {
    let ambient = Double(ambientSlider.value)
    let outputPower = round(10000*process_input_data(ambient))/10000
    outputPowerLabel.text = "\(outputPower)"
  }
}


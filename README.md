# FuzzyliteAndSwift
FuzzyLite Integration with Swift

## The reference source for the FuzzyLite library has been included from http://www.fuzzylite.com/downloads/. The FuzzyLite library was authored by [Juan Rada-Vilela](http://www.fuzzylite.com/jcrada), Ph.D. and the public C++ github repository is available at https://github.com/fuzzylite/fuzzylite.

1. Create new single-view iOS application project (sample project name is FuzzyLiteTemplate)
2. Copy entire fuzzylite/ directory into the Xcode project -> Make sure to select Create groups in the Add Dialog
3. Add a new C++ (including header) file to the project (in the sample project it is named CPlusPlusBridge). When you add it, Xcode will ask you if you want to generate a project-wide bridging header permission pop-up. Go ahead and accept.
4. You should see 4 new files being created:
	- CPlusPlusBridge.cpp/.h
	- FuzzyLiteTemplate-Bridging-Header.h
5. Take a look at the sample FuzzyLiteTemplate-Bridging-Header.h file. The reason for this is that from Swift you cannot call C++ code directly. You can only call C functions.
6. Take a look at the sample files in the Xcode project and you should be able to run a sample demo application built using the FuzzyLite library code. The UI slider is the Ambient value and the output power is shown in the output label. The demo fuzzy logic model is from the default QT FuzzyLite application

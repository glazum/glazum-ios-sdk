##Introduction

[Glazum](http://www.glazum.com) is a simple and effective tool for collecting feedback from your iOS users. Ask them any question you like at any moment you wish!

Just create new question, bind it to a marker in your app and decide who and when should see it. All answers get collected and processed automatically.
You can see and manage them in the dashboard page in real time.

An example of Glazum API usage you can see [here](https://github.com/glazum/glazum-ios-example) 

##Considerations

Information gathered by the SDK is sent to the Glazum website in real time.

Glazum SDK works with iOS 4.3+, armv7+armv7s, with both device and simulator support. It has been tested using Xcode 4.0.

##Integration

1. Add Glazum.framework files to your project: File -&gt; Add Files to " "
    1. Find and select the folder that contains the SDK
    2. Make sure that "Copy items into destination folder (if needed)" is checked
    3. Set Folders to "Create groups for any added folders"
    4. Select all targets that you want to add the SDK to
2. Verify that Glazum.framework has been added to the Link Binary With Libraries Build Phase for the targets you want to use the SDK with     
    1. Select your Project in the Project Navigator
    2. Select the target you want to enable the SDK for
    3. Select the Build Phases tab
    4. Open the Link Binary With Libraries Phase
    5. If Glazum.framework is not listed, drag and drop the library from your Project Navigator to the Link Binary With Libraries area
    6. Repeat Steps 2 - 5 until all targets you want to use the SDK with have the SDK linked
3. Add CoreGraphics.framework to your Link Binary With Libraries Build Phase
    1. Select your Project in the Project Navigator
    2. Select the target you want to enable the SDK for
    3. Select the Build Phases tab
    4. Open the Link Binary With Libraries Phase
    5. If CoreGraphics.framework is not listed, Click the + to add a new library
    6. Find CoreGraphics.framework in the list and add it
    7. Repeat Steps 2 - 6 until all targets you want to use the SDK with have CoreGraphics.framework
4. In your Application Delegate:
    1. Import Glazum: `#import <Glazum/Glazum.h>`                      

        ***NOTE:*** Rather than importing `Glazum/Glazum.h` in every file you may add the above line into you pre-compiled header (`<projectname>_Prefix.pch`) file inside of the


            #ifdef __OBJC__ 


        section. This will give you access to the SDK across all files.
    2. Get your Application IPD which you can find at [Glazum Dashboard](http://www.glazum.com/dashboard/)
    3. Launch Glazum with your Application ID

		- (BOOL) application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {   
			// ...
			[Glazum startUp:@"YOUR-APP-IDENTIFIER"];
			// ...
		}

##Setting markers

Place named markers wherever you need in your code. Later you will bind questions to these markers.

	[Glazum setMarker:@"button pressed"];

Markers in the code identify places where Glazum is allowed to show questions. Please note that it doesn’t mean that a question will be shown every time the marker’s code is executed. Glazum allows you to set a list of conditions required to show a question to the user. The question will be shown only when all these conditions are met.

Setting markers is a one-time operation. You don’t need to do any code changes to your app in order to add/edit or turn on/off questions. Our advice is to set as many markers as possible.

Please note, that there are two system markers :app launched and :app entered foreground. Therefore there is no need manually set markers for these events.

##Questions preview

If you wonder how question will look like in your app, just use:

	[Glazum testQuestionWithType:kQuestionWithSingleLineTextAnswer];
where `kQuestionWithSingleLineTextAnswer` is one of the five available question types:

	typedef enum {
		kQuestionWithSingleLineTextAnswer,
		kQuestionWithMultiLineTextAnswer,
		kQuestionWithSingleAnswerSelection,
		kQuestionWithMultipleAnswerSelection,
		kQuestionWithNetPromoterScore
	}QuestionType;
	
##Before and after callbacks

You can specify code blocks that will be called before and after a question is shown.

doBefore block takes one boolean argument willShowQuestion. When it's true, the question will be asked right after this block is executed. doAfter block takes one argument questionWasShown. If questionWasShown is true, the question was actually shown.

Using doBefore/doAfter may be useful for preparing your app for showing question and resuming its previous state after the question is shown.

	[Glazum setMarker:@"button pressed"
		   doBefore:^(BOOL willShowQuestion) {
			//prepare application for the question to be asked
	}
			doAfter:^(BOOL questionWasShown) {
			//cleanup everything and restore previous state
	}];
	
Please note, that you can pass nil instead of either doBefore or doAfter.

	[Glazum setMarker:@"button pressed"
		   doBefore:nil
			doAfter:^(BOOL questionWasShown) {
			//cleanup everything and resume your app
	}];
	
##Identify your app users

If your app in some way indentify users, you can do this with Glazum too. For example, to identify the user with his email (authenticate) just call:

	[Glazum setUserIdentifier:@"test@example.com"];

When Glazum:setUserIdentifier is called, user identifier value is stored permantently and applied to all markers that are executed afterwards. To remove user identifier (for example to deauthenticate user) just call setUserIdentifier with nil argument:
	
	[Glazum setUserIdentifier:nil];
	
##Set additional properties

Aside from identifying your app's users, you can set question showing criteria based on a custom variable. To use custom variables just call:

	[Glazum setCustomVariable:@"true" named:@"ab test share"];

The value will be stored permanently. To remove it call setCustomVariable with nil variable argument:

	[Glazum setCustomVariable:nil named:@"ab test share"];
	
##Setting Glazum options

###GlazumOptionDebug

If you need Glazum log messages in your console, just set GlazumOptionDebug option like this:

	[Glazum setOptions:@{GlazumOptionDebug:@YES}];

###GlazumOptionDebugLogHandler

If you have your own custom logger, you can set custom block to receive all debug messages

	[Glazum setOptions:@{GlazumOptionDebugLogHandler:^(NSString *message) {
				//your custom debug logger logic
			}
	}];
#ScriptingBridgeDox

[ScriptingBridge][scriptingbridge] headers and [Doxygen][doxygen] configuration for a range of Apple and third party OS X applications.

Apple's [ScriptingBridge][scriptingbridge] (SB) is an application automation technology for [Cocoa languages][cocoa-languages].

The [sdp][sdp] tool is used to generate an appropriate Objective-C header from the application bundle. Correct use of the `--basename` option creates more readable output.

The full [Doxygen][doxygen] generated documentation set and downloadable zip archives can be viewed at [Mugginsoft][mugginsoft].

#Adding new SB application headers

To add a new header:

1. Clone this.
2. Run the [sdp][sdp] tool on the application bundle.
3. Insert the generated header into the `Applications` folder hierarchy using the template below.
4. Send us a pull.

Folder hierarchy template:

`Applications\<company>\<app>\OS-X-<ver>\<app-ver>\<app.h>`

[cocoa-languages]:http://en.wikipedia.org/wiki/Cocoa_(API)#Implementations_and_Bindings

[scriptingbridge]:https://developer.apple.com/library/mac/#documentation/Cocoa/Conceptual/ScriptingBridgeConcepts/Introduction/Introduction.html

[sdp]:https://developer.apple.com/library/mac/#documentation/Cocoa/Conceptual/ScriptingBridgeConcepts/UsingScriptingBridge/UsingScriptingBridge.html

[doxygen]:http://doxygen.org

[mugginsoft]:http://www.mugginsoft.com/kosmictask/ScriptingBridge



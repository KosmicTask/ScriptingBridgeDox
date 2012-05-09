#ScriptingBridgeDox

An archive of [ScriptingBridge][scriptingbridge] headers and [Doxygen][doxygen] configuration for a range of Apple and third party OS X applications.

Apple's [ScriptingBridge][scriptingbridge] (SB) is an application automation technology for [Cocoa languages][cocoa-languages].

The [sdp][sdp] tool is used to generate an appropriate Objective-C header from the application bundle. Correct use of the `--basename` option creates more readable output. [sdp][sdp] is included as part of Apple's Xcode developer tool chain.

The full [Doxygen][doxygen] generated documentation set and downloadable zip archives can be viewed at [Mugginsoft][mugginsoft].

#Adding new SB application headers

To add a new header:

1. Clone this.
2. Run the [sdp][sdp] tool on the application bundle.
3. Insert the generated header into the `Applications` folder hierarchy using the template below.
4. Send us a pull.

Folder hierarchy template:

`Applications\<company>\<app>\OS-X-<ver>\<app-ver>\<app.h>`

#Email submission

SB application headers will also be accepted by email for inclusion in this archive. Send the following to `support@mugginsoft.com`.

1. Application company name (Apple, Adobe, etc).
2. Application name and link.
3. OS X version of machine that generated the header.
4. Application version as quoted in the About panel.
5. The header itself, either in the body of the email or as an attachment. Use the [sdp][sdp] tool.

[cocoa-languages]:http://en.wikipedia.org/wiki/Cocoa_(API)#Implementations_and_Bindings

[scriptingbridge]:https://developer.apple.com/library/mac/#documentation/Cocoa/Conceptual/ScriptingBridgeConcepts/Introduction/Introduction.html

[sdp]:https://developer.apple.com/library/mac/#documentation/Cocoa/Conceptual/ScriptingBridgeConcepts/UsingScriptingBridge/UsingScriptingBridge.html

[doxygen]:http://doxygen.org

[mugginsoft]:http://www.mugginsoft.com/kosmictask/ScriptingBridge



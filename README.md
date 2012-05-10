#ScriptingBridgeDox

An archive of [ScriptingBridge][scriptingbridge] headers and [Doxygen][doxygen] configurations for a range of Apple and third party OS X applications (OS X 10.6 and above).

Apple's [ScriptingBridge][scriptingbridge] (SB) is an application automation technology for [Cocoa languages][cocoa-languages].

The [sdp][sdp] tool is used to generate an appropriate Objective-C header from the application bundle. [sdp][sdp] is included as part of Apple's [Xcode][xcode] developer tool chain. When using Xcode 4 it will be necessary to install the command line tools under Preferences - Downloads - Components.

The full [Doxygen][doxygen] generated documentation set and downloadable zip archives can be viewed at [Mugginsoft][mugginsoft].

#Adding new SB application headers

To add a new header:

1. Clone this.
2. Run the [sdp][sdp] tool on the application bundle. See below for details.
3. Insert the generated header into the `Applications` folder hierarchy using the template below.
4. Send us a pull.

Folder hierarchy template:

	Applications\<company>\<appname>\OS-X-<ver>\<appname-ver>\<app.h>

#Generating SB headers using sdef and sdp

The [sdp][sdp] tool is used in conjunction with the [sdef][sdef] tool to generate a ScriptingBridge header file from an application  bundle `appname.app`.

	sdef "/path/to/appname.app" | sdp -fh -N appname -o appname.h 

The `-N` (name) option sets the application prefix that will be used within the generated header file. Failure to set this correctly may result in the use of the default `Application` term which results in less readable output e.g: the generated application classname will be `ApplicationApplication`as opposed to `AppnameApplication`. This option is also required for application bundles containing spaces in the app name such as `Adobe Photoshop CS5`.

#Email submission

SB application headers will also be accepted by email for inclusion in this archive. Send the following to `support@mugginsoft.com`.

1. Application company name (Apple, Adobe, etc).
2. Application name and link.
3. OS X version of machine that generated the header (OS X 10.6 and above only please).
4. Application version as quoted in the About panel.
5. The SB header itself, either in the body of the email or as an attachment. Use the [sdp][sdp] tool as described above.

[cocoa-languages]:http://en.wikipedia.org/wiki/Cocoa_(API)#Implementations_and_Bindings

[scriptingbridge]:https://developer.apple.com/library/mac/#documentation/Cocoa/Conceptual/ScriptingBridgeConcepts/Introduction/Introduction.html

[sdp]:https://developer.apple.com/library/mac/#documentation/Cocoa/Conceptual/ScriptingBridgeConcepts/UsingScriptingBridge/UsingScriptingBridge.html

[sdef]: http://developer.apple.com/library/mac/#documentation/Darwin/Reference/ManPages/man5/sdef.5.html

[doxygen]:http://doxygen.org

[mugginsoft]:http://www.mugginsoft.com/kosmictask/ScriptingBridge

[xcode]: https://developer.apple.com/xcode/


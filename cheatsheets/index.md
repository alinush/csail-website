Cheatsheets
===========

Mac/OS X
--------

 * [Home/End key for terminal is Ctrl+A and Ctrl+E](https://apple.stackexchange.com/questions/71101/how-do-i-make-%E2%8C%98%E2%86%90-and-%E2%8C%98%E2%86%92-work-for-home-end-combo-for-terminal)
 * [Show hidden files in Finder](http://www.tekrevue.com/tip/show-hidden-files-on-mac-os-x/)
 * [Lock or sleep your Mac](http://www.tekrevue.com/tip/the-fastest-way-to-lock-or-sleep-your-screen-in-mac-os-x/)
 * `sudo scutil --set HostName macbook`
 * `brew cask install texmaker`
 * [iTerm2 Solarized](https://github.com/altercation/solarized/tree/master/iterm2-colors-solarized)
 * [Add lock screen button](https://apple.stackexchange.com/questions/95819/mbp-lock-screen-hotkey-without-sleeping)
 * [Add maximize window shortcut](http://osxdaily.com/2013/03/22/5-simple-window-management-keyboard-shortcuts-to-improve-workflow-in-mac-os-x/)
   + Keyboard shortcut does not work for Chrome for some reason
 * [iTerm2 pane navigation shortcuts](https://stackoverflow.com/questions/9246235/iterm2-keyboard-shortcut-split-pane-navigation)
   + New pane with `Cmd + D` or `Cmd + Shift + D`
 * [Keyboard repeat rate](https://stackoverflow.com/questions/4489885/how-can-i-increase-the-cursor-speed-in-terminal)
 * [Symlink /home to /Users](https://apple.stackexchange.com/questions/44058/mac-os-x-how-to-symlink-home-to-users)
 * [Cut and paste files in Finder](http://hints.macworld.com/article.php?story=201107211337186)
   + `Cmd + C` and `Cmd + Option + V` 
 * `Cmd + F3` to show desktop

[Bash](../bash/)
-------------

#### Cutting up a video file using `avconv`

    avconv -i [input file] -ss [start time hh:mm:ss.milisecs] -t [duration in secs] -codec copy [output file]

Or use `-to [end time hh:mm:ss.milisecs]` to indicate the time at which to stop cutting instead of the duration.  
**Note:** If you chose to not re-encode (i.e., you use the `-codec copy` option), in many cases the trimmed/cut output file will not have the first 5 seconds of the video, which is super-annoying. To fix this, just remove the `-codec copy`, which will take a longer time but give you an actual good cut.

[ViM](../vim/)
-----------

emacs
-----

Commands like `M-x` are executed by typing the Meta key + x (on Linux, Meta key is Alt)

Commands like `C-x` are executed by typing the Ctrl key + x

 - `C-x o`: switches buffers (panes/windows)
 - `C-x C-c`: exits emacs

[Git](../git/)
-----------

[LaTeX](../latex/)
------------------

SSH
---

### Setting up an SSH tunnel

Suppose you have a machine at `server.com` that has a service running on port 3333, but you cannot
access that port on `server.com` due to a firewall.

You can _forward_ that port to a local port 9999 on your machine, if you can SSH into `server.com`

    ssh -f -N -L 9999:127.0.0.1:3333 user@server.com

    -f puts ssh in background
    -N makes it not execute a remote command

You can simplify this whole process with a config file.

    Host tunnel
        HostName server.com
        # this is optional, if you have a special key for server.com
        IdentityFile ~/.ssh/private.key
        LocalForward 3333 127.0.0.1:9999
        User user

sed
---

### Using sed to redo your \#include's

    sed 's/#include \"..\/Core\/Core.h\"/#include \<Core.h\>/g' 

Eclipse
-------

### Adding whitespace

There were a lot of `cout<<"hsds"<<i<<endl;` calls in the code, and I
wanted to space out the `<<`.

Search: (\S)(<<)(\S)
Replace with: $1 $2 $3

Be sure to check "Regular expressions." You probably don't need to capture the `<<` part.

rdiff
-----

### How to compute a delta and patch a file

    alinush@x220 [~] (master %) $ vim new-file.txt     #  hello alin has apples;
    alinush@x220 [~] (master %) $ vim old-file.txt     #  hello johnny has apples.
    alinush@x220 [~] (master %) $ rdiff signature old-file.txt sig
    alinush@x220 [~] (master %) $ rdiff delta sig new-file.txt delta.txt
    alinush@x220 [~] (master %) $ rdiff patch old-file.txt delta.txt patched.txt
    alinush@x220 [~] (master %) $ cat old-file.txt ; cat new-file.txt ; cat patched.txt ;
    hello alin has apples;
    hello johnny has apples.
    hello johnny has apples.

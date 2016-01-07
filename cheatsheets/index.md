Cheatsheets
===========

Mac/OS X
--------

 * [Home/End key for terminal is Ctrl+A and Ctrl+E](https://apple.stackexchange.com/questions/71101/how-do-i-make-%E2%8C%98%E2%86%90-and-%E2%8C%98%E2%86%92-work-for-home-end-combo-for-terminal)
 * [Show hidden files in Finder](http://www.tekrevue.com/tip/show-hidden-files-on-mac-os-x/)
 * [Lock or sleep your Mac](http://www.tekrevue.com/tip/the-fastest-way-to-lock-or-sleep-your-screen-in-mac-os-x/)
 * `sudo scutil --set HostName macbook`

[Bash](../bash/)
-------------

[ViM](../vim/)
-----------

[Git](../git/)
-----------

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

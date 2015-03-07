Cheatsheets
===========

[Bash](bash/)
-------------

ViM
---

### Replace matched group

I wanted to search for 2 leading spaces followed by any uppercase character
and insert " * " followed by  that upper case character. So I needed to refer to that matched character:

    :%s/^  \([A-Z]\)/ * \1/g

The `^` refers to the beginning of a line, the `\(` and `\)` are for grouping a match. The `[A-Z]` matches any single upper case character. The `\1` refers to the uppercase character matched in `\([A-Z]\)`.

### Search for something with `/` then replace it with `%s`

    /keyword
    :%s//new_keyword/g

### Replace a visually selected yanked block

You have to press `y` for yanking and then type in `:%s/` and then press `Ctrl+R` and then press `"` to get the text to show up in in the `%s/<here>/` section.

    y:%s/<Ctrl+R>"/new text/g

### Change each 'foo' to 'bar' for all lines from the current line (.) to the last line ($) inclusive
    
    :.,$s/foo/bar/g

### Display whitespace characters (tabs, spaces, newlines, etc.)

    :set list

If you want to change the way they are displayed you can use `listchars`:

    :set listchars=eol:$,tab:>-,trail:~,extends:>,precedes:<

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

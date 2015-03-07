**TODO:** make sure this is accessible at http://alinush.org/2012/06/06/linux-cheatsheet/

### Searching PDFs

    find /path -name '*.pdf' -exec sh -c 'pdftotext "{}" - | grep --with-filename --label="{}" --color "your pattern"' \;

### Getting a properly formatted date for file names

    date +%Y-%m-%d-%H-%M-%S

...for, December 20th, 2014, 3:31AM this will output

    2014-12-20-03-31-08

### Get RAM DIMM info

    sudo dmidecode --type 17 | more

### Zip a directory

    zip -r archive.zip /path/to/directory/

### Computing with floating point numbers using `bc`

    echo "4.5 / 2.5" | bc -l

    # Computes log_2(256)
    echo "l(256)/l(2)" | bc -l

### Renaming tricks

This renames all directories in the current working directory from `b6-r9-a16` into `b06-r09-a16` (bulk renaming).

    rename 's/b(\d+)_r(\d+)_a(\d+)/sprintf("b%02d-r%02d-a%02d", $1, $2, $3)/e' *

This renames all directories in the current working directory from
`results_blablabla` into `blablabla` (bulk renaming).

    rename 's/results_.*b/b/g' *

### How to hash a directory (quick)

    find /usr/include -type f -print0 | sort -z | xargs -0 sha256sum | sha256sum

### Automatic error handling in BASH

The single and double quotes are important here to properly evaluate (at the right time and place)
`$LINENO` and `$BASH_COMMAND`.

    trap 'echo; echo ERROR: a command failed at line $LINENO: \"$BASH_COMMAND\"; echo;' ERR; set -e;

### Generate SSH key non-interactively (without file path & password prompt)

    ssh-keygen -f key.rsa -t rsa -N ""

### Replace a string in a file

    sed -i 's/text-to-replace/replacement-text/g' file.txt

### Remove all files that are not added in SVN

For those awful days when you do an...

    svn status

...and 9,572 files pop up:

    svn status | egrep '^\?' | cut -c8- | xargs rm -r

### Generate public key file from OpenSSH private key file

    # Just type ssh-keygen -y and you will be
    # prompted for the private key file path
    ssh-keygen -y

### Searching for a string/pattern in all files inside a directory

    find directory/ -type f -exec grep pattern '{}' \;
    grep -ircl --exclude=*.{png,jpg} "foo=" *
    grep -Ir --exclude="*\.svn*" "pattern" *

Where *directory* and *pattern* should be changed to suit your needs.

### Cut columns from the output of ls (directory listings)

More information on this can be found [here](http://lowfatlinux.com/linux-columns-cut.html)

    ls usr/bin/ppc_4xxFP-* -l | cut -d' ' -f9

### Prevent sudo from asking you for password

Add a line like the following to your `/etc/sudoers file`, where `alinush` is your username:

    alinush ALL=(ALL) NOPASSWD: ALL

### Finding text in all your source (.c or .cpp) files

I wanted to find the file that contained the definition of a function called `vmJump`, but
I did not know how to find all `.c/.cpp` files.

    find . \( -name "*.c" -or -name "*.cpp" \) -print | xargs grep "vmJump"

### Listing all the files in a package

I was trying to see where libgcj's files were placed after installing in Fedora using yum.

    rpm -q libgcj -l

### VARIABLE="something" versus export VARIABLE="something"

I was running make on a makefile that was launching sub-shells to execute some
commands. The prerequisite was that `JAVA_HOME` be defined with `export
JAVA_HOME`, but I only did `JAVA_HOME="/usr/java/default"`. The end result
was that those children shells did not have `JAVA_HOME` defined and my
build would fail. I was very surprised. After I did export `JAVA_HOME` it
all worked. Here's what I mean. Suppose you were typing this in your
bash shell.

    VAR="smth"
    echo $VAR
    smth
    bash
    echo $VAR

    exit
    export VAR
    bash
    echo $VAR
    smth

### How to invoke a script such that it will set/modify the caller shell's environment variables?

I had this script that set some environment variables and I noticed that just typing 
`./cross-compile-setup` in bash did not have any effect.

    #!/bin/bash
    # File name: cross-compile-setup

    export CROSS_COMPILE=ppc_4xxFP-
    PATH=$PATH:/opt/eldk/usr/bin:/opt/eldk/bin

It turns out you need to invoke it using:

    source ./cross-compile-setup

### How to check file types

    [ -L "/path/to/symlink" ] # 'true' if the path is a symlink 
    [ -f "/path/to/file" ]    # 'true' if the path is a regular file 
    [ -d "/path/to/dir" ]     # 'true' if the path is a directory 

More on this can be found on TLDP [here](http://tldp.org/LDP/abs/html/fto.html). 

### How to get the inode of the file pointed to by a symlink

    stat -L --printf "%i\\n" /path/to/symlink

### Iterate through a sequence of numbers

    END=203

    for i in $(seq 1 $END); 
        do echo $i; 
    done

### String operations

    string="some string" 
    ${#string}           # return length of string 
    ${string#substring}  # remove shortest match of substring from front 
    ${string##substring} # remove longest match of substring from front 
    ${string%substring}  # remove shortest match of substring from the end 
    ${string%%substring} # remove longest match of substring from the end

More [here](http://tldp.org/LDP/abs/html/string-manipulation.html).

### Refer to arguments from previous command

Use `Alt - <arg. #i>` to "copy" the i-th argument and `Alt-Ctrl-Y` to "paste" it in the current
command.

### Argument handling

Code:

    scriptdir=$(dirname $(readlink -f $0))

    function print_usage() {
	    echo "Usage: $0 [OPTIONS]"
	    echo
	    echo "OPTIONS:"
	    echo "  -m, --multi-param [param1 param2 ... paramN]"
	    echo "  -o, --optional-param [param]"
	    echo "  -s, --enable-smth"
	    echo "  -l, --log-file <file>"
	    echo "  -h, --help     displays this help message"
	    echo
    }

    multi_param=
    optional_param=
    smth="false"
    logfile=

    while true; do
        case "$1" in
            --multi-param | -m )
                shift || break
                while [ "${1:0:1}" != "-" -a -n "$1" ]; do
                    multi_param="$multi_param $1"
                    shift || break
                done ;;
            --optional-param | -o )
                shift || break
                if [ "${1:0:1}" != "-" -a -n "$1" ]; then
                    optional_param=$1
                shift || break
                fi ;;
            --log-file | -l )
                [ -n "$2" ] && {
                    logfile="$2";
                    shift 2 || break;
                }
                
                [ -z "$2" ] && shift || break
                
                ;;
            --enable-smth | -s )
                smth="true"
                shift 1 || break ;;
            --help | -h )
                print_usage
                exit 0 ;;
            * )
                if [ -n "$1" ]; then
                    echo "WARNING: Unknown argument given: '$1'"
                    # TODO: exit 1 when bad args are given, if desirable
                fi
                shift || break ;;
            esac
    done

    echo "Script started in directory `pwd` (stored in $scriptdir)"
    echo 
    echo "PARAMETERS:"
    echo "==========="
    echo "multi-param:     $multi_param"
    echo "optional-param:  $optional_param"
    echo "log-file:        $logfile"
    echo "smth:            $smth"
    echo "[remaining]:     $@"

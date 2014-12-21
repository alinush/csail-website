CSAIL Website
=============

If you ever run into permission problems, like I did when using `~/public_html` as a Git repo, then see the [TIG help page](http://tig.csail.mit.edu/wiki/TIG/CreatingPersonalWebPages).

To set the proper permissions, you can do:

    cd ~
    fs setacl public_html/ system:anyuser none www read; 

    cd ~/public_html
    for d in `find -type d`; do 
        if [ $d != "." -a $d != ".." ]; then 
            fs setacl $d system:anyuser none www read; 
        fi
    done

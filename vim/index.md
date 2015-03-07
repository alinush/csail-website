**TODO:** this page needs to be reachable from http://alinush.org/2012/08/05/vim-cheatsheet/

### Commands

`u` - Undo  
`Ctrl+R` - Redo   
`y` - Copy   
`d` - Cut   
`v` - Paste   
`/\<l\>` - Search for single letter `l`  
`/pattern` - Search for 'pattern'  
`:set ignorecase` - Sets the default search mode to case insensitive  
`:set number` - Displays line numbers   
`/pattern\c` - Search for 'pattern' (case insensitive)   
`/\cpattern` - Search for 'pattern' (case insensitive)   
`/pat\ctern` - Search for 'pattern' (case insensitive)  
`:%s/search/replace/g` - Replace 'search' with 'replace' in the entire file   
`Ctrl+w, v` - Split window vertically   
`Ctrl+w, s` - Split window horizontally   
`Ctrl+w, w` - Switch between split windows   
`Ctrl+w, q` - Quit a window   
`Shift+g` - Go to end of file  
`gg` - Go to beginning of file   
`Ctrl+v, Tab` - Insert a real tab ('\t') character. Useful when you have spaces set instead of tabs.   
`>>` - Indent a line   
`3>>` - Indent a line three times  
`Shift+v, jj>` - Select & indent two lines   
`>%` - Indent a bracketed block (move cursor to starting bracket {)   
`]p` - Paste & indent code  

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

### References

 - [http://www.worldtimzone.com/res/vi.html](http://www.worldtimzone.com/res/vi.html)
 - [http://www.tuxfiles.org/linuxhelp/vimcheat.html](http://www.tuxfiles.org/linuxhelp/vimcheat.html)
 - [http://stackoverflow.com/questions/235839/how-do-i-indent-multiple-lines-quickly-in-vi](http://stackoverflow.com/questions/235839/how-do-i-indent-multiple-lines-quickly-in-vi)


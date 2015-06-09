### See all modifications for a file

    git log -p <filename>

### Tag a commit and push it up

    # Use git tag -l to see tags
    # Use git tag -d <tagname> to delete a tag
    git tag <tagname>

    git push origin <tagname>


### See the modifications in a certain commit

By commit hash: `git show <COMMIT-HASH>`

The `i`-th to last commit: `git show HEAD~i`

### See the modifications between two commits

    git show <hash1> <hash2>
    git show HEAD~i HEAD~j
    git show HEAD~i HEAD

### Adding a submodule

    git submodule add --name 6.857-spring-2105 git@github.com:alinush/6.857-lecture-notes.git 6.857-spring-2015

### See all modifications for a file

    git log -p <filename>

### Diffing, but ignoring whitespace changes

    git show --ignore-space-change <commit>
    git diff --ignore-space-change <commit1> <commit2>

### Squashing the last, say, 4 commits

    git rebase -i HEAD~4

See [here](http://gitready.com/advanced/2009/02/10/squashing-commits-with-rebase.html) for more details.  
**WARNING:** Only do this if you haven't pushed those commits to someone else. Otherwise, inconsistent repos will be created and you won't be able to merge them anymore.

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

### Update Git submodule(s) to latest commit from origin

One simple command:

    git submodule foreach git pull origin master

More complicated ([source here](https://stackoverflow.com/questions/5828324/update-git-submodule-to-latest-commit-on-origin)):

    # get the submodule initially
    git submodule add ssh://bla submodule_dir
    git submodule init

    # time passes, submodule upstream is updated
    # and you now want to update

    # change to the submodule directory
    cd submodule_dir

    # checkout desired branch
    git checkout master

    # update
    git pull

    # get back to your project root
    cd ..

    # now the submodules are in the state you want, so
    git commit -am "Pulled down update to submodule_dir"

### Remove a Git submodule

From [SO post](https://stackoverflow.com/questions/1260748/how-do-i-remove-a-submodule)

    mv a/submodule a/submodule_tmp
    git submodule deinit -f -- a/submodule
    rm -rf .git/modules/a/submodule
    git rm -f a/submodule
    # Note: a/submodule (no trailing slash)

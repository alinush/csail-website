:autocmd BufWritePost *.md
\   silent execute '!pandoc --mathjax -s -S -f markdown --include-in-header style.css -t html "<afile>" >"'.
\   expand('<afile>:t:r').'".html'

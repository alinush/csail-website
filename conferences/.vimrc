:autocmd BufWritePost *.md
\   silent execute '!pandoc --mathjax -s -S -f markdown -t html "<afile>" >"'.
\   expand('<afile>:t:r').'".html'

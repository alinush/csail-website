for f in *.pdf; do
	title=`echo $f | cut -d'-' -f 3- | tr '-' ' '`
	title="${title%.*}"
	title="${title^}"
	echo "<li><a href=\"$f\">$title</a>: </li>"
done

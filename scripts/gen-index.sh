echo -n "" >index.html

echo "<ul>" >>index.html
for f in *.pdf; do
	echo -e "\t<li><a href=\"$f\">$f</a></li>" >>index.html
done
echo "</ul>" >>index.html

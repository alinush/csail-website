#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * unescapeStr(char * s);

char tape[65536];

void b(void)
{
	printf("%s\n\nint main(int argc, char ** argv)\n{\n\tstrcpy(tape, \"%s\");\n\tb();\n\treturn 0;\n}\n\nchar * unescapeStr(char * s)\n{\n\tint l = strlen(s);\n\tchar * n = malloc(l * 2 + 1);\n\tchar * p = n;\n\tfor(int i = 0; i < l; i++) {\n\t\tswitch(s[i])\n\t\t{\n\t\t\tcase '\\n':\n\t\t\t\t*p++ = '\\\\';\n\t\t\t\t*p++ = 'n';\n\t\t\t\tbreak;\n\t\t\tcase '\\t':\n\t\t\t\t*p++ = '\\\\';\n\t\t\t\t*p++ = 't';\n\t\t\t\tbreak;\n\t\t\tcase '\\\\':\n\t\t\t\t*p++ = '\\\\';\n\t\t\t\t*p++ = '\\\\';\n\t\t\t\tbreak;\n\t\t\tcase '\\\"':\n\t\t\t\t*p++ = '\\\\';\n\t\t\t\t*p++ = '\\\"';\n\t\t\t\tbreak;\n\t\t\tdefault:\n\t\t\t\t*p++ = s[i];\n\t\t\t\tbreak;\n\t\t}\n\t\t*p = 0;\n\t}\n\n\treturn n;\n}\n", tape, unescapeStr(tape));
}

int main(int argc, char ** argv)
{
	strcpy(tape, "#include <stdio.h>\n#include <string.h>\n#include <stdlib.h>\n\nchar * unescapeStr(char * s);\n\nchar tape[65536];\n\nvoid b(void)\n{\n\tprintf(\"%s\\n\\nint main(int argc, char ** argv)\\n{\\n\\tstrcpy(tape, \\\"%s\\\");\\n\\tb();\\n\\treturn 0;\\n}\\n\\nchar * unescapeStr(char * s)\\n{\\n\\tint l = strlen(s);\\n\\tchar * n = malloc(l * 2 + 1);\\n\\tchar * p = n;\\n\\tfor(int i = 0; i < l; i++) {\\n\\t\\tswitch(s[i])\\n\\t\\t{\\n\\t\\t\\tcase '\\\\n':\\n\\t\\t\\t\\t*p++ = '\\\\\\\\';\\n\\t\\t\\t\\t*p++ = 'n';\\n\\t\\t\\t\\tbreak;\\n\\t\\t\\tcase '\\\\t':\\n\\t\\t\\t\\t*p++ = '\\\\\\\\';\\n\\t\\t\\t\\t*p++ = 't';\\n\\t\\t\\t\\tbreak;\\n\\t\\t\\tcase '\\\\\\\\':\\n\\t\\t\\t\\t*p++ = '\\\\\\\\';\\n\\t\\t\\t\\t*p++ = '\\\\\\\\';\\n\\t\\t\\t\\tbreak;\\n\\t\\t\\tcase '\\\\\\\"':\\n\\t\\t\\t\\t*p++ = '\\\\\\\\';\\n\\t\\t\\t\\t*p++ = '\\\\\\\"';\\n\\t\\t\\t\\tbreak;\\n\\t\\t\\tdefault:\\n\\t\\t\\t\\t*p++ = s[i];\\n\\t\\t\\t\\tbreak;\\n\\t\\t}\\n\\t\\t*p = 0;\\n\\t}\\n\\n\\treturn n;\\n}\\n\", tape, unescapeStr(tape));\n}");
	b();
	return 0;
}

char * unescapeStr(char * s)
{
	int l = strlen(s);
	char * n = malloc(l * 2 + 1);
	char * p = n;
	for(int i = 0; i < l; i++) {
		switch(s[i])
		{
			case '\n':
				*p++ = '\\';
				*p++ = 'n';
				break;
			case '\t':
				*p++ = '\\';
				*p++ = 't';
				break;
			case '\\':
				*p++ = '\\';
				*p++ = '\\';
				break;
			case '\"':
				*p++ = '\\';
				*p++ = '\"';
				break;
			default:
				*p++ = s[i];
				break;
		}
		*p = 0;
	}

	return n;
}

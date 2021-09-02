all: 0-hreadelf 1-hreadelf 2-hreadelf

FILES_0 = 0-readelf.c prints1.c prints2.c prints3.c prints4.c prints5.c helpers.c
FILES_1 = 1-readelf.c helpers.c helpers2.c sectionPrints1.c sectionPrints2.c sectionPrints3.c
FILES_2 = 2-readelf.c helpers.c helpers2.c programPrints1.c programPrints2.c programPrints3.c programPrints4.c programPrints5.c

0-hreadelf:
	gcc -Wall -Werror -Wextra -pedantic $(FILES_0) -o 0-hreadelf

1-hreadelf:
	gcc -Wall -Werror -Wextra -pedantic $(FILES_1) -o 1-hreadelf

2-hreadelf:
	gcc -Wall -Werror -Wextra -pedantic $(FILES_2) -o 2-hreadelf

.PHONY: clean, check, memcheck, memfull

clean:
	rm -f *.o 0-hreadelf 1-hreadelf 2-hreadelf 100-hreadelf
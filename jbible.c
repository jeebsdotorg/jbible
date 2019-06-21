#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "granthorner.h"

void print_usage(void) {
	printf("Usage:");

	printf("\n\t$ jbible day 1\n");
	printf("\t\tList 1   Matthew             Chapter 1\n");
	printf("\t\tList 2   Genesis             Chapter 1\n");
	printf("\t\tList 3   Romans              Chapter 1\n");
	printf("\t\tList 4   I Thessalonians     Chapter 1\n");
	printf("\t\tList 5   Job                 Chapter 1\n");
	printf("\t\tList 6   Psalms              Chapter 1\n");
	printf("\t\tList 7   Proverbs            Chapter 1\n");
	printf("\t\tList 8   Joshua              Chapter 1\n");
	printf("\t\tList 9   Isaiah              Chapter 1\n");
	printf("\t\tList 10  Acts                Chapter 1\n");

	printf("\n\t$ jbible day 777\n");
	printf("\t\tList 1   Luke                Chapter 21\n");
	printf("\t\tList 2   Genesis             Chapter 29\n");
	printf("\t\tList 3   Hebrews             Chapter 10\n");
	printf("\t\tList 4   Revelation of John  Chapter 19\n");
	printf("\t\tList 5   Job                 Chapter 33\n");
	printf("\t\tList 6   Psalms              Chapter 27\n");
	printf("\t\tList 7   Proverbs            Chapter 2\n");
	printf("\t\tList 8   Judges              Chapter 6\n");
	printf("\t\tList 9   Isaiah              Chapter 27\n");
	printf("\t\tList 10  Acts                Chapter 21\n");
}

void print_reading_plan(struct grant_horner_s *gh, unsigned day) {
	unsigned i;
	struct book_list_position_s blp;

	for (i = 0; i < GRANT_HORNER_LIST_COUNT; ++i) {
		printf("List %-4d", (i+1));
		blp = grant_horner_book_list_position_by_day(&gh->lists[i], day);
		printf("%-20sChapter %d\n", blp.book->name, blp.chapter);
	}
}

int main(int argc, char *argv[]) {
	struct grant_horner_s *gh = NULL;
	unsigned day = 0;

	gh = grant_horner_alloc();
	if (!gh) {
		return EXIT_FAILURE;
	}

	if (!*(++argv) || strcmp("day", *argv)) {
		print_usage();
		goto cleanup;
	}

	if (!*(++argv) || (day = atoi(*argv)) <= 0) {
		print_usage();
		goto cleanup;
	}

	print_reading_plan(gh, day);

cleanup:
	grant_horner_free(gh);
	gh = NULL;

	return EXIT_SUCCESS;
}

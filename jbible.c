#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "granthorner.h"

void print_usage(void) {
	printf("Usage:\n");
	printf("\t$ jbible day 1\n");
	printf("\t$ jbible day 777\n");
}

void print_reading_plan(struct grant_horner_s *gh, gh_big_uint day) {
	struct book_list_position_s blp;
	gh_small_uint i;

	for (i = 0; i < GRANT_HORNER_LIST_COUNT; ++i) {
		blp = grant_horner_book_list_position_by_day(&gh->lists[i], day);
		printf("List %-4d%-20sChapter %d\n", (i+1), blp.book->name, blp.chapter);
	}
}

int main(int argc, char *argv[]) {
	struct grant_horner_s *gh = NULL;
	gh_big_uint day = 0;

	gh = grant_horner_alloc();
	if (!gh) {
		return EXIT_FAILURE;
	}

	if (!*(++argv) || strcmp("day", *argv)) {
		print_usage();
		goto cleanup;
	}

	if (!*(++argv) || (day = atoll(*argv)) <= 0) {
		print_usage();
		goto cleanup;
	}

	print_reading_plan(gh, day);

cleanup:
	grant_horner_free(gh);
	gh = NULL;

	return EXIT_SUCCESS;
}

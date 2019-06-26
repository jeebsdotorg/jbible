#ifndef GRANT_HORNER_H
#define GRANT_HORNER_H

#include "jeebs.h"

#define GRANT_HORNER_LIST_COUNT 10
#define BOOK_MAX_NAME_LEN 64
#define BOOK_MAX_ABBR_LEN 8

struct book {
	char name[BOOK_MAX_NAME_LEN];	/* name of book */
	char abbr[BOOK_MAX_ABBR_LEN];	/* osisID (book abbreviation) */
	u8 chapters;			/* number of chapters in book */
};

struct book_list {
	struct book *books;		/* books in a Grant Horner list */
	u8 count;			/* number of books in the list */
};

/* represents position in a list, calculated for a particular day */
struct book_list_pos {
	struct book *book;		/* the book */
	u8 chapter;			/* the chapter */
};

/* represents the lists defined by Grant Horner */
struct grant_horner {
	struct book_list lists[GRANT_HORNER_LIST_COUNT];
};

/* memory management */
struct grant_horner *grant_horner_alloc(void);
void grant_horner_free(struct grant_horner *gh);

/* number crunching to return the struct book_list_pos */
struct book_list_pos grant_horner_book_list_position_by_day(struct book_list *bl, u64 day);

#endif

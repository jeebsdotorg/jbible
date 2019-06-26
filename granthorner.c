#include <stdlib.h>
#include <string.h>

#include "granthorner.h"

/* Internal Functions */
static struct book *books_alloc(u8 i) {
	struct book *books = NULL;
	size_t size_of_book = sizeof(*books);

	switch(i) {
	case 0:
		books = calloc(size_of_book, 4);
		break;
	case 1:
		books = calloc(size_of_book, 5);
		break;
	case 2:
		books = calloc(size_of_book, 8);
		break;
	case 3:
		books = calloc(size_of_book, 14);
		break;
	case 4:
		books = calloc(size_of_book, 3);
		break;
	case 5:
		books = calloc(size_of_book, 1);
		break;
	case 6:
		books = calloc(size_of_book, 1);
		break;
	case 7:
		books = calloc(size_of_book, 12);
		break;
	case 8:
		books = calloc(size_of_book, 17);
		break;
	case 9:
		books = calloc(size_of_book, 1);
		break;
	}

	return books;
}

static void books_free(struct book_list *bl) {
	if (bl && bl->books) {
		free(bl->books);
		bl->books = NULL;
	}
}

static void books_set_properties(struct book *b, char *name, char *abbr, u8 chapters) {
	strncpy(b->name, name, BOOK_MAX_NAME_LEN-1);
	strncpy(b->abbr, abbr, BOOK_MAX_ABBR_LEN-1);
	b->chapters = chapters;
}

static void books_populate(struct book_list *bl, u8 i) {
	struct book *b = bl->books;

	switch(i) {
	case 0:
		books_set_properties(b++, "Matthew", "Matt", 28);
		books_set_properties(b++, "Mark", "Mark", 16);
		books_set_properties(b++, "Luke", "Luke", 24);
		books_set_properties(b++, "John", "John", 21);
		break;
	case 1:
		books_set_properties(b++, "Genesis", "Gen", 50);
		books_set_properties(b++, "Exodus", "Exod", 40);
		books_set_properties(b++, "Leviticus", "Lev", 27);
		books_set_properties(b++, "Numbers", "Num", 36);
		books_set_properties(b++, "Deuteronomy", "Deut", 34);
		break;
	case 2:
		books_set_properties(b++, "Romans", "Rom", 16);
		books_set_properties(b++, "I Corinthians", "1Cor", 16);
		books_set_properties(b++, "II Corinthians", "2Cor", 13);
		books_set_properties(b++, "Galatians", "Gal", 6);
		books_set_properties(b++, "Ephesians", "Eph", 6);
		books_set_properties(b++, "Philippians", "Phil", 4);
		books_set_properties(b++, "Colossians", "Col", 4);
		books_set_properties(b++, "Hebrews", "Heb", 13);
		break;
	case 3:
		books_set_properties(b++, "I Thessalonians", "1Thess", 5);
		books_set_properties(b++, "II Thessalonians", "2Thess", 3);
		books_set_properties(b++, "I Timothy", "1Tim", 6);
		books_set_properties(b++, "II Timothy", "2Tim", 4);
		books_set_properties(b++, "Titus", "Titus", 3);
		books_set_properties(b++, "Philemon", "Phlm", 1);
		books_set_properties(b++, "James", "Jas", 5);
		books_set_properties(b++, "I Peter", "1Pet", 5);
		books_set_properties(b++, "II Peter", "2Pet", 3);
		books_set_properties(b++, "I John", "1John", 5);
		books_set_properties(b++, "II John", "2John", 1);
		books_set_properties(b++, "III John", "3John", 1);
		books_set_properties(b++, "Jude", "Jude", 1);
		books_set_properties(b++, "Revelation of John", "Rev", 22);
		break;
	case 4:
		books_set_properties(b++, "Job", "Job", 42);
		books_set_properties(b++, "Ecclesiastes", "Eccl", 12);
		books_set_properties(b++, "Song of Solomon", "Song", 8);
		break;
	case 5:
		books_set_properties(b++, "Psalms", "Ps", 150);
		break;
	case 6:
		books_set_properties(b++, "Proverbs", "Prov", 31);
		break;
	case 7:
		books_set_properties(b++, "Joshua", "Josh", 24);
		books_set_properties(b++, "Judges", "Judg", 21);
		books_set_properties(b++, "Ruth", "Ruth", 4);
		books_set_properties(b++, "I Samuel", "1Sam", 31);
		books_set_properties(b++, "II Samuel", "2Sam", 24);
		books_set_properties(b++, "I Kings", "1Kgs", 22);
		books_set_properties(b++, "II Kings", "2Kgs", 25);
		books_set_properties(b++, "I Chronicles", "1Chr", 29);
		books_set_properties(b++, "II Chronicles", "2Chr", 36);
		books_set_properties(b++, "Ezra", "Ezra", 10);
		books_set_properties(b++, "Nehemiah", "Neh", 13);
		books_set_properties(b++, "Esther", "Esth", 10);
		break;
	case 8:
		books_set_properties(b++, "Isaiah", "Isa", 66);
		books_set_properties(b++, "Jeremiah", "Jer", 52);
		books_set_properties(b++, "Lamentations", "Lam", 5);
		books_set_properties(b++, "Ezekiel", "Ezek", 48);
		books_set_properties(b++, "Daniel", "Dan", 12);
		books_set_properties(b++, "Hosea", "Hos", 14);
		books_set_properties(b++, "Joel", "Joel", 3);
		books_set_properties(b++, "Amos", "Amos", 9);
		books_set_properties(b++, "Obadiah", "Obad", 1);
		books_set_properties(b++, "Jonah", "Jonah", 4);
		books_set_properties(b++, "Micah", "Mic", 7);
		books_set_properties(b++, "Nahum", "Nah", 3);
		books_set_properties(b++, "Habakkuk", "Hab", 3);
		books_set_properties(b++, "Zephaniah", "Zeph", 3);
		books_set_properties(b++, "Haggai", "Hag", 2);
		books_set_properties(b++, "Zechariah", "Zech", 14);
		books_set_properties(b++, "Malachi", "Mal", 4);
		break;
	case 9:
		books_set_properties(b++, "Acts", "Acts", 28);
		break;
	}

	bl->count = b - bl->books;
}

static u8 grant_horner_chapters_in_book_list(struct book_list *bl) {
	u8 chapters = 0;
	u8 i;

	for (i = 0; i < bl->count; ++i) {
		chapters += bl->books[i].chapters;
	}

	return chapters;
}

/* API Functions */
struct grant_horner *grant_horner_alloc(void) {
	struct grant_horner *gh = NULL;
	u8 i;

	gh = calloc(sizeof(struct grant_horner), 1);
	if (!gh) {
		return NULL;
	}

	for (i = 0; i < GRANT_HORNER_LIST_COUNT; ++i) {
		if (!(gh->lists[i].books = books_alloc(i))) {
			grant_horner_free(gh);
			return NULL;
		}

		books_populate(&gh->lists[i], i);
	}

	return gh;
}

void grant_horner_free(struct grant_horner *gh) {
	u8 i;

	if (gh) {
		for (i = 0; i < GRANT_HORNER_LIST_COUNT; ++i) {
			books_free(&gh->lists[i]);
		}

		free(gh);
	}
}

struct book_list_pos grant_horner_book_list_position_by_day(struct book_list *bl, u64 day) {
	struct book_list_pos blp;
	struct book *current_book;
	u8 current_chapter;
	u8 chapters;

	chapters = grant_horner_chapters_in_book_list(bl);
	current_chapter = ((day - 1) % chapters) + 1;

	for (current_book = bl->books; current_chapter > current_book->chapters; ++current_book) {
		current_chapter -= current_book->chapters;
	}

	blp.book = current_book;
	blp.chapter = current_chapter;
	return blp;
}

#ifndef LIST_H
#define LIST_H


typedef struct Text Text;
typedef struct Word Word;
typedef struct WordNode WordNode;
typedef struct TextNode TextNode;






struct Text * TextList_new (void);
void Text_addLast(Text * self, Word * data);
void Text_free(struct Text ** self);
int Text_count(struct Text * self);
void Text_removeNode(Text * self, struct WordNode * min);
void Text_cleanList(Text * self);
void TextNode_free(struct TextNode ** self);
struct TextNode * TextNode_new(Text sent);
void Text_change(Text * text1, Text* text2);


Word * Word_new(const char * str);
WordNode * Word_remove(Text * self);
WordNode * Word_removeFirst(Text * self);
WordNode * Text_removeFirst(Text * self);
void Word_free(struct WordNode ** self);
struct WordNode * Text_minWord(Text * self);
Word * getWord(WordNode * out);
WordNode * WordNode_copy(Text * self);
char * Word_getString(Word * self);
Word * Text_getWord(Text * self, int wordIndex);
void Word1_free(Word ** self);
struct WordNode * WordNode_new(Word word);



#endif
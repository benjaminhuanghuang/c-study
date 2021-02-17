struct word
{
  char *data;
};

struct sentence
{
  struct word *data;
  int word_count; //denotes number of words in a sentence
};

struct paragraph
{
  struct sentence *data;
  int sentence_count; //denotes number of sentences in a paragraph
};

struct document
{
  struct paragraph *data;
  int paragraph_count; //denotes number of paragraphs in a document
};


struct document get_document(char* text) {

    typedef struct paragraph _p;
    typedef struct sentence _s;
    typedef struct word _w;
    
    struct document doc;

    doc.data = (_p*) malloc(sizeof(_p));
    doc.paragraph_count = 0;

    doc.data[0].data = (_s*) malloc(sizeof(_s));
    doc.data[0].sentence_count = 0;

    doc.data[0].data[0].data = (_w*) malloc(sizeof(_w));
    doc.data[0].data[0].word_count = 0;

    doc.data[0].data[0].data[0].data = (char*) malloc(sizeof(char));
    
    int p, s, w, c;
    p = s = w = c = 0;

    while (*text != '\0'){

        if (*text == ' ' || *text == '.') {
            doc.data[p].data[s].word_count = ++w;

            if (*text == '.') {
                doc.data[p].sentence_count = ++s;

                if (*(text + 1) == '\n') {
                    doc.paragraph_count = ++p;

                    doc.data = (_p*) realloc(doc.data, (p + 1) * sizeof(_p));
                    doc.data[p].data = (_s*) malloc(sizeof(_w));
                    doc.data[p].sentence_count = s = 0;

                    text++;
                }

                doc.data[p].data = (_s*) realloc(doc.data[p].data, (s + 1) * sizeof(_s));
                doc.data[p].data[s].data = (_w*) malloc(sizeof(_w));
                doc.data[p].data[s].word_count = w = 0;

            }

            doc.data[p].data[s].data = (_w*) realloc(doc.data[p].data[s].data, (w + 1) * sizeof(_w));
            doc.data[p].data[s].data[w].data = (char*) malloc(sizeof(char));
            c = 0;
        } else {
            doc.data[p].data[s].data[w].data = (char*) realloc(doc.data[p].data[s].data[w].data, (c + 2) * sizeof(char));
            doc.data[p].data[s].data[w].data[c] = *text;
            doc.data[p].data[s].data[w].data[++c] = '\0';
        }
        text++;
    }
    return doc;
}
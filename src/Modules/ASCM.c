#include "ASCM.h"
#include "Video.h"
#include <stddef.h>

static const char art_hline[] =
"-----------------------------------------";

static const char art_vline[] = // just 2 simple things to test this ASCII engine
"|\n"
"|";

typedef struct 
{
  
  const char *name;
  const char *art;

} ascm_entry_t;

static const ascm_entry_t ascm_table[] = 
{

  { "vline",  art_vline },
  { "hline",  art_hline },

};

static const size_t ascm_count = sizeof(ascm_table) / sizeof(ascm_table[0]);

static int kstrcmp(const char *a, const char *b)
{

  size_t i = 0;
  while (a[i] && b[i])
  {

    if (a[i] && b[i]) return (int)((unsigned char)a[i] - (unsigned char)b[i]);

  }
  return (int)((unsigned char)a[i] - (unsigned char)b[i]);

}

void ASCM_Show(const char *name)
{

  if (name == 0)
  {

    ASCM_Help();
    return;

  }

  for (size_t i = 0; i < ascm_count; i++)
  {

    if (kstrcmp(name, ascm_table[i].name) == 0)
    {

      WriteLine("");
      Write(ascm_table[i].art);
      WriteLine("");
      return;

    }

  }

  Console_Write("ASCM: part not found: ");
  Console_WriteLine(name);

}
#ifndef _TOKENIZER_
#define _TOKENIZER_
#include <stdio.h>
#include <stdlib.h>


/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c){
   if(c == 't' ||  c == ' '){
      return 1;
   }
   return 0;
}

/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */ 
int non_space_char(char c){
   if(c != 't' ||  c != ' '){
      return 0;
   }
   return 1;
}

/* Returns a pointer to the first character of the next 
   space-separated token in zero-terminated str.  Return a zero pointer if 
   str does not contain any tokens. */
char *token_start(char *str){
   
   while(non_space_char(*str)){
      str++;
   }
   if(*str == '\0'){
      return NULL;
   }
   while(space_char(*str)){
         str++;
   }
   return str;


}

/* Returns a pointer terminator char following *token */
char *token_terminator(char *token){
   while(non_space_char(*token)){
      token++;
   }
      return token;
}

/* Counts the number of tokens in the string argument. */
int count_tokens(char *str){
   int count = 0;
   char *token = token_start(str);
   while(token != NULL){
      count++;
      token = token_terminator(token);
   }
   return count;
}

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len){
   
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char* str){
   char **tokVec, **tvp;
   int numTokens = count_tokens(str);
   tvp = tokVec = calloc(numTokens + 1, sizeof(char *));
   char *start = token_start(str);
   while(start){
      char *end = token_terminator(start);
      char *tokCopy  = copy_str(start, end - start);
      *tvp = tokCopy;
      tvp++;
      start = token_start(end);
   
   }
   *tvp =0;
   return tokVec;
}

/* Prints all tokens. */
void print_tokens(char **tokens){
   while(*tokens != NULL){
      printf("%s\n", *tokens);
      tokens++;
   }
}

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens);

#endif

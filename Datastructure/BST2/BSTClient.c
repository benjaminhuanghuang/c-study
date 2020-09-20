//Sandy Sang
//Zsang
//Assignment 3
//CMPS12B/M
//---------------------------------------------------------------------
// BSTClient.c
// Input oriented Test client for Binary Search Tree ADT
// see file BSTUI.h for definition of commands and acceptable input details.
// 
//---------------------------------------------------------------------

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include "BST.h"
#include "BSTUI.h"		


/******************  function prototypes  *****************************/

void doQuit();
void showHelp();
void doErase( BSTObj **ptrT);
void doHeight( BSTObj *T);
void doHeight();
void doInsert(BSTObj **ptrT, char *arg);
void doPrint(BSTObj *T, char *order);
void doFind(BSTObj *T, char *term);
int inputLengthOK(char *inputStr);

/*
 * parseInput 
 *    Processes the text string input and divides the input into words that are 
 *    returned on w1, w2, w3
 *    This supports commands that have at most one argument:
 *    return the command in w1, first argument in w2, w3 for trailing junk
 *
 *    Return value indicates the outcome of parsing. Could be OK result which is command that
 *    was detected, e.g.
 *	  CMD_HELP
 *    of it could be an error was detected, e.g.
 *	  NO_ARGS_NEEDED	  
 *
 */
int parseInput(char *input, char *w1, char *w2, char *w3){
    int	    numArgs;

    /*
     * take the raw input string and read the contents to determine the action
     * fill in the argument if the command requires one.
     */
    
    // break the request up into words separated by whitespace
 
    numArgs = sscanf(input, "%s %s %s", w1, w2, w3);
    //printf("numArg = %d from sscanf w1 = %s, w2= %s, w3= %s\n",numArgs, w1, w2, w3);


    if (numArgs == EOF ) {
	// no words, tell the user they can get help
        return CMD_NONE;
    }

    if (numArgs == 0 ) {
	// no words, tell the user they can get help
        return CMD_NONE;
    }
  
    if (strcasecmp(CMD_HELP_STR, w1) == 0) {
        if (numArgs > 1) {
	    return NO_ARGS_NEEDED;
        }
        else {
	    return(CMD_HELP);
        }
    }

    if (strcasecmp(CMD_ERASE_STR, w1) == 0) {
        if (numArgs == 1) {
        return CMD_HELP;
        }
        else {
        return(CMD_HELP);
	// your code here
    }
	}

    if (strcasecmp(CMD_QUIT_STR, w1) == 0) {
        if (numArgs == 1) {
        return CMD_QUIT;
        }
        else {
        return(CMD_HELP);
	// your code here
    }
}

    if (strcasecmp(CMD_HEIGHT_STR, w1) == 0) {
        if (numArgs == 1) {
        return CMD_HEIGHT;
        }
        else {
        return(CMD_HELP);
	// your code here
    }
}
    
    if (strcasecmp(CMD_INSERT_STR, w1) == 0) {
        if (numArgs > 1) {
        return CMD_INSERT;
        }
        else {
        return(CMD_HELP);
          // your code here
 
    }
}

    if (strcasecmp(CMD_PRINT_STR, w1) == 0) {
        if (numArgs == 1) {
        return CMD_PRINT;
        }
        else {
        return(CMD_HELP);
        
    }
}

    if (strcasecmp(CMD_FIND_STR, w1) == 0) {
        if (numArgs > 1) {
        return CMD_FIND;
        }
        else {
        return(CMD_HELP);


    }
}
    // don't know what this is, doesn't match any commands
    
    return CMD_UNK;
}

/*
 * Parse the input, do the command or generate and error
 */
int main(int argc, char* argv[]){

    BSTObj  *T;
    char    str[MAX_INPUT_LENGTH+3];	// one more for one character over and null
    char    cmdStr[MAX_INPUT_LENGTH +1];
    char    arg1[MAX_INPUT_LENGTH +1];
    char    arg2[MAX_INPUT_LENGTH +1];
    char   *inputStr;
    int     action;
    int     input_from_terminal;
    
    T = NULL;

    input_from_terminal = isatty(fileno(stdin));
    
    if (input_from_terminal)
	printf(COMMAND_PROMPT);

    // note that fgets reads the newline character "\n" and includes this in the string
    while ( (inputStr  = fgets(str,  MAX_INPUT_LENGTH + 2, stdin)) != NULL) {
 
        //printf("fgets returned %s\n", inputStr);
	
        // check input line length
	if(!inputLengthOK(inputStr)) { 
	   action = INPUT_TOO_LONG; 	// too big!
	}
        else {
            //printf("got request |%s|\n", inputStr);
            action = parseInput(inputStr, cmdStr, arg1, arg2);
            //printf("got action = %d\n", action);
	}

	switch(action) {
        
            case CMD_NONE:
		break;
	    case INPUT_TOO_LONG:
		printf(ERR_TOO_LONG, MAX_INPUT_LENGTH);
		break;
            case EXTRA_ARG:
		printf(ERR_EXTRA_ARG, arg1);
		break;
  	    case NEED_MORE_ARG:
		printf(ERR_NEED_ARG);
		break;
  	    case NO_ARGS_NEEDED:
		printf(ERR_NO_ARGS_NEEDED, cmdStr);
		break;
	    case CMD_HELP:
		showHelp();
		break;
	    case CMD_ERASE:
		doErase(&T);
		break;
	    case CMD_QUIT:
		doQuit();
		break;
	    case CMD_HEIGHT:
		doHeight(T);
		break;
	    case CMD_INSERT:
		doInsert(&T, arg1);
		break;
	    case CMD_PRINT:
		doPrint(T, arg1);
                break;
            case CMD_FIND:
		doFind(T, arg1);
   		break;
            case CMD_UNK:
		printf(ERR_UNK_CMD, cmdStr);
                break;
	    default:
		fprintf(stderr, "at default statement\n");
        }
        *arg1 = '\0';
        *arg2 = '\0';
        *cmdStr = '\0';

        if (input_from_terminal )
           printf(COMMAND_PROMPT);
    }
   
    exit(1);
}


/***************************************************************************************
 *
 * the functions that actually do the command requested by the user
 */

void doQuit() {
    printf("\n");
    exit(0);
}
void showHelp() {
    printf(HELP_MESSAGE);
}

void doErase( BSTObj **ptrT) {
 makeEmpty(&ptrT);
 printf(MSG_NONE);
}

void doHeight( BSTObj *T) {
 int height = treeHeight(T, 0);
 printf(MSG_HEIGHT);
}

// insert the argument into the tree
void doInsert(BSTObj **ptrT, char *arg) {

    //char* inputStr;
    //inputStr  = fgets(*arg,  MAX_INPUT_LENGTH + 2, stdin);


    insert(arg, ptrT);
    //if (insert(*ptrT, arg) != -1){
        printf(MSG_NONE);

    //}else
    //printf(MSG_NONE);

}

// figure out which print the user wanted and do it
// if there is no ordering then use inorder as the default
void doPrint(BSTObj *T, char *order) {
    if (*order = NULL){
        inorderTraverse(&T, order);
    }
  
        //preorderTraverse(&T, order);

     }


void doFind(BSTObj *T, char *term) {
    int exist = find(T, term);
    if (exist){
    printf(MSG_FOUND);
}else{
    printf(ERR_NOT_FOUND);
}

    
}

//check if we have read past the allowed max, not that fgets passes the newline character in a string
// fgets does a read of MAX_INPUT_LENGTH + 1
int inputLengthOK(char *inputStr) {
    
    int  length;

    //printf("input check got |%s|\n", inputStr);
    // confirm that the string is no just a "\n"
    // check that the "\n" 

    length = strlen(inputStr);

    //printf("input check length is %d\n", length);

    // your code here
    return TRUE;
}

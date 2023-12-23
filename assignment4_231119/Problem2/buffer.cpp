/* P3:
 * File: p3beffer.cpp
 * -------------------
 * This file implements EditorBuffer
 */
#include <iostream>
// #include "CSC3002OJActive/assignment4/buffer.h"
// #include "CSC3002OJActive/assignment4/SimpleTextEditor.h"
#include "buffer.h"
#include "SimpleTextEditor.cpp"
using namespace std;

/*
 * Implementation notes: EditorBuffer constructor
 * ----------------------------------------------
 * This function initializes an empty editor buffer, represented
 * as a doubly linked list.  In this implementation, the ends of
 * the linked list are joined to form a ring, with the dummy cell
 * at both the beginning and the end.  This representation makes
 * it possible to implement the moveCursorToEnd method in constant
 * time, and reduces the number of special cases in the code.
 */

EditorBuffer::EditorBuffer()
{
   start = cursor = new Cell;
   start->next = start;
   start->prev = start;
}

/* TODO PART:
 * Implementation notes: EditorBuffer destructor
 * ---------------------------------------------
 * The destructor must delete every cell in the buffer.  Note
 * that the loop structure is not exactly the standard idiom for
 * processing every cell within a linked list, because it is not
 * legal to delete a cell and later look at its next field.
 */

EditorBuffer::~EditorBuffer()
{
   // TODO
   Cell *a = start;
   while (a != NULL)
   {
      Cell *next = a->next;
      delete a;
      a = next;
      if (a == next){
         break;
      }
   }
   if (a != NULL){
      delete a;
   } 
}

/* TODO PART:
 * Implementation notes: cursor movement
 * -------------------------------------
 * In a doubly linked list, each of these operations runs in
 * constant time.
 */

void EditorBuffer::moveCursorForward()
{
   // TODO
   if (cursor->next != start)
   {
      cursor = cursor->next;
   }
}

void EditorBuffer::moveCursorBackward()
{
   // TODO
   if (cursor != start)
   {
      cursor = cursor->prev;
   }
}

void EditorBuffer::moveCursorToStart()
{
   // TODO
   cursor = start;
}

void EditorBuffer::moveCursorToEnd()
{
   // TODO
   cursor = start->prev;
}

/* TODO PART:
 * Implementation notes: insertCharacter, deleteCharacter
 * ------------------------------------------------------
 * This code is much like that used for the traditional linked
 * list except that more pointers need to be updated.
 */

void EditorBuffer::insertCharacter(char ch)
{
   // TODO
   Cell *ins = new Cell;
   ins->ch = ch;
   ins->next = cursor->next;
   ins->prev = cursor;
   cursor->next->prev = ins;
   cursor->next = ins;
   cursor = ins;
}

void EditorBuffer::deleteCharacter()
{
   // TODO
   Cell *del = cursor->next;
   //cout << "ddd" << endl;
   if (cursor != start && del == start)
   {
      del = cursor;
      cursor->prev->next = start;
      cursor->next->prev = cursor->prev;
    //  delete cursor;
      cursor = cursor->prev;
   }else if (cursor == del){
         delete cursor;
   }else{
      cursor->next = del->next;
      del->next->prev = cursor;
      //delete del;
   }
}

/* TODO PART:
 * Implementation notes: getText and getCursor
 * -------------------------------------------
 * The getText method uses the standard linked-list pattern to loop
 * through the cells in the linked list.  The getCursor method counts
 * the characters in the list until it reaches the cursor.
 */

string EditorBuffer::getText() const
{
   // TODO
   string text = "";
   if (start == NULL || start->next == NULL)
   {
      return text;
   }

   Cell *te = new Cell;
   te = start->next;
   while (te != start)
   {
      text.push_back(te->ch);
      te = te->next;
   }
   return text;
}

int EditorBuffer::getCursor() const
{
   // TODO
   Cell *te = new Cell;
   te = start;
   int i = 0;
   while (te != cursor)
   {
      i += 1;
      te = te->next;
   }
   return i;
}

/* DO NOT modify the main() part */
int main()
{
   string cmd;
   EditorBuffer buffer;
   while (getline(cin, cmd))
   {
      executeCommand(buffer, cmd);
   }
   return 0;
}
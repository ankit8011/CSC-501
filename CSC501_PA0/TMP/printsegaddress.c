// Name : Ankit Manendra
// Unity ID : amanend
// Assignment Number: PA0

#include <stdio.h>

extern long etext;
extern long edata;
extern long end;

void printsegaddress(){

kprintf("void printsegaddress() \n");
kprintf("Current: ");
kprintf("etext[0x%08x] = 0x%08x, " , &etext-1, *(&etext-1));
kprintf("edata[0x%08x] = 0x%08x, " , &edata-1, *(&edata-1));
kprintf("ebss[0x%08x] = 0x%08x \n" , &end-1, *(&end-1));
kprintf("Preceding: ");
kprintf("etext[0x%08x] = 0x%08x, " ,&etext-2,*(&etext-2));
kprintf("edata[0x%08x] = 0x%08x, " ,&edata-2, *(&edata-2));
kprintf("ebss[0x%08x] = 0x%08x \n" ,&end-2, *(&end-2));
kprintf("After: ");
kprintf("etext[0x%08x] = 0x%08x, " , &etext, *(&etext));
kprintf("edata[0x%08x] = 0x%08x, " , &edata, *(&edata));
kprintf("ebss[0x%08x] = 0x%08x \n" , &end, *(&end));

}


// Reference: https://piazza.com/class/jqmpp3k2nng5u0?cid=43 : Address indicating the end of text would be the address
// following the etext address, hence etext-1 is used for current 

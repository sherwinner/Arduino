#include <ir_Lego_PF_BitStreamEncoder.h>
#include <IRremote.h>
#include <boarddefs.h>
#include <IRremoteInt.h>
 
// Instantiate IRremote on Pin 3.
IRsend irsend;
 
void setup()
{
  irsend.enableIROut(38);
}
 
void loop()
{
  irsend.mark(1000);
  irsend.space(1000);
}

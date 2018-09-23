/* Project 65
 *
 * Bootstrap test
 *
 */

 const int clock_pin = 3;
 const int num_pins = 8;
 /* address bus pins hooked to high byte of address bus */
 const int address_bus_pins[] = {5,6,7,8,9,10,11,12};

 void setup ()
 {
   pinMode (clock_pin, OUTPUT);
   for (int i = 0; i < num_pins; ++i)
     pinMode (address_bus_pins[i], INPUT);

   Serial.begin (115200);
 }

 int address;
 int last_address = 0;
 int reset_count = 0;
 int roll_count = 0;

 void loop ()
 {
   // cycle clock - slowly
   digitalWrite (clock_pin, LOW);
   delay (1);
   digitalWrite (clock_pin, HIGH);

   // read address bus
   address = 0;
   for (int i = 0; i < num_pins; ++i)
   {
     address = address << 1;
     address += (digitalRead (address_bus_pins[num_pins-i-1]) == HIGH)?1:0;
   }

   // write the address as it changes, so we have some indication
   // that things are happening.
   if (address != last_address)
   {
     Serial.print (int2hex ((address >> 4)));
     Serial.println (int2hex (address & 0xf));
   }

   if (address == 0xea)
   {
     if (last_address == 0xea)
       ;
     else if (last_address == 0xe9)
     {
       // we've completed a full loop through memory
       Serial.print ("roll count: ");
       Serial.println (roll_count++);
     }
     else
     {
       // we've jumped directly to EAxx instead of
       // getting there by incrementing address register.
       Serial.print (reset_count++);
       Serial.println (": Reset detected!!!!");
     }
   }

   last_address = address;
 }

 char int2hex (int h)
 {
   if (h >= 0 && h <= 9)
   {
     return '0' + h;
   }
   else if (h >= 10 && h <= 15)
   {
     return 'a' + h-10;
   }
   else
     return '?';
 }

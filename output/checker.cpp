//Return true if checker did not fail
bool checker(bool p0, bool const reset = false){
   static int NEXT_STATE = 0;
   if(reset){
      NEXT_STATE = 0;
    }
   switch(NEXT_STATE){

      case 0:
         if(1){
            NEXT_STATE = 1;
         }
         break;

      case 1:
         if(p0){
            NEXT_STATE = 2;
         }
         if(!p0){
            return false;
         }
         break;

      case 2:
         break;

      return true;
   }
}

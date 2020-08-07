//Return true if checker did not fail
bool checker(bool p0, bool p1, bool const reset = false){
   static int NEXT_STATE = 0;
   if(reset){
      NEXT_STATE = 0;
    }
   switch(NEXT_STATE){

      case 0:
         if(!p0){
            NEXT_STATE = 1;
         }
         if(p0){
            NEXT_STATE = 2;
         }
         if(p0){
            NEXT_STATE = 3;
         }
         break;

      case 1:
         break;

      case 2:
         if(p1){
            NEXT_STATE = 1;
         }
         if(!p1){
            return false;
         }
         break;

      case 3:
         if(!p0){
            NEXT_STATE = 1;
         }
         if(p0){
            NEXT_STATE = 3;
         }
         break;

      return true;
   }
}

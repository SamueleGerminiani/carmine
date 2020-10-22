#define INIT_STATE 0
//Return true if checker did not fail
inline bool checker(bool p0, bool p1, bool p2, bool const reset = false){
   if(reset){
      NEXT_STATE = INIT_STATE;
    }
   switch(NEXT_STATE){

      case 0:
         if((!p0 || p2)){
            NEXT_STATE = 0;
         }
         if((p0 && p1)){
            NEXT_STATE = 1;
         }
         if((p0 && !p1)){
            return false;
         }
         break;

      case 1:
         if(p2){
            NEXT_STATE = 0;
         }
         if((p1 && !p2)){
            NEXT_STATE = 1;
         }
         if((!p1 && !p2)){
            return false;
         }
         break;
   }

   return true;
}

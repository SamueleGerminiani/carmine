const int ERROR = -1;
void checker(bool const reset, bool& param_fail, bool& param_fail_if_last_cycle, bool p0){
   static int NEXT_STATE = 0;
   if(reset){
      NEXT_STATE = 0;
      return;
    }
   param_fail = false;
   switch(NEXT_STATE){

      case 0:
         if(1){
            NEXT_STATE = 1;
         }
         else{
            NEXT_STATE = ERROR;
            param_fail = true;
         }
         break;

      case 1:
         if(p0){
            NEXT_STATE = 2;
         }
         if(!p0){
            NEXT_STATE = 3;
         }
         else{
            NEXT_STATE = ERROR;
            param_fail = true;
         }
         break;

      case 2:
         if(1){
            NEXT_STATE = 2;
         }
         else{
            NEXT_STATE = ERROR;
            param_fail = true;
         }
         break;

      case 3:
         if(1){
            NEXT_STATE = 3;
         }
         else{
            NEXT_STATE = ERROR;
            param_fail = true;
         }
         break;

      case ERROR: 
         param_fail = true;
         break;
   }
}

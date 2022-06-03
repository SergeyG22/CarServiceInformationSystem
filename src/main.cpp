#include "Facades/application.h"


int main() {
   setlocale(LC_ALL, "russian");
   std::shared_ptr<Application>exec = std::make_unique<Application>();
   exec->applicationExec();
   return 0;
}
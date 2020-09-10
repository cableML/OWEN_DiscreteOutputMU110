#include <OWEN/DiscreteOutputMU110.hpp>

#include <iostream>
#include <thread>

auto main(int argc, char** argv) -> int32_t
{
   auto discreteOutput = OWEN::DiscreteOutputMU110{"/dev/cu.usbserial-14510", 115200, 17};
//   auto const communicationOptions = discreteOutput.GetCommunicationOptions();
//   if (communicationOptions.has_value())
//   {
//     std::cout << communicationOptions.value() << std::endl;
//   }
//   else
//   {
//     std::cout << "error" << std::endl;
//   }

//   auto const discreteOutputOptions = discreteOutput.GetDiscreteOutputOptions();
//   if (discreteOutputOptions.has_value())
//   {
//     std::cout << discreteOutputOptions.value() << std::endl;
//   }
//   else
//   {
//     std::cout << "error" << std::endl;
//   }
   auto const discreteOutputState = discreteOutput.GetDiscreteOutputsState();
   for (auto i = 0; i < 255; ++i)
   {
     std::this_thread::sleep_for(std::chrono::seconds(1));
     discreteOutput.SetDiscreteOutputsState(i);
   }
   return 0;
}
#include <vector>
#include <iostream>

#include "scan.h"


int main(int argc, char ** argv) {

  if (argc != 6) {
    std::cerr << argv[0] << " <DATABASE> <EXPERIMENT> <ch> <MinCT> <MaxCT>" << std::endl;
    // std::cerr << argv[0] << " <DATABASE> <EXPERIMENT> <chan seq> <MinCT list> <MaxCT list>" << std::endl;
    return 1;
  }

  int ch = atoi(argv[3]);
  int min = atoi(argv[4]);
  int max = atoi(argv[5]);

  int maxaps = 0;

  //std::vector<ProbeResponse> results;
  int results;

  ScanningCampaing scan(argv[1], argv[2]);
  scan.init();

  scan.prepareIRD();


  results = scan.getAPsMaxApproach(ch, min, max);
  printf("getAPsMaxApproach(%d, %d, %d) = %d \n", ch, min, max, results);

/*

  for (int i = 0; i<50; i++) {
        results = scan.getAPsMaxApproach(ch, min, max);
        printf("getAPsMaxApproach(%d, %d, %d) = %d \n", ch, min, max, results);

        //for (auto presp : results) {
        //  printf("  %s - op_ch: %d - nic_ch: %d\n",
        //      presp.ssid.c_str(), presp.op_channel, presp.nic_channel);
        //}

        //if (results >= maxaps) {
        //        maxaps = results;
        //}
        //printf("\n");
  }
  //printf("max: %d \n", maxaps);

*/

  return 0;
}

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
  double totalAPs = 0;
  double ceroAPs = 0;

  //std::vector<ProbeResponse> results;
  int results = 0;

  ScanningCampaing scan(argv[1], argv[2]);
  scan.init();

  scan.prepareIRD();

  for (int i = 0; i<50; i++) {
        //results = scan.getAPs(ch, min, max);
	
	results = scan.getAPsForSequenceMaxApproach(ch, min, max);

        //printf("getAPs(%d, %d, %d) = %d \n", ch, min, max, results.size());
	printf("getAPs(%d, %d, %d) = %d \n", ch, min, max, results);
	//printf("%d \n", results.size());


        //for (auto presp : results) {
        //  printf("  %s - op_ch: %d - nic_ch: %d\n",
        //      presp.ssid.c_str(), presp.op_channel, presp.nic_channel);
        //}

        //if (results.size() >= maxaps) {
	if (results >= maxaps) {
                //maxaps = results.size();
                maxaps = results;
        }
        //printf("\n");

	//totalAPs = totalAPs + results.size();
	totalAPs = totalAPs + results;
	//printf("totalAPs: %d\n", totalAPs);

	//if (results.size() == 0) {
	if (results == 0) {
		//printf("	0\n");
		ceroAPs++;
	}
  }
  //printf("ceroAPs: %f\n", ceroAPs);
  //printf("totalAPs: %f\n", totalAPs);
  
  printf("valor máximo de APs: %d \n", maxaps);
  printf("valor promedio de APs: %f \n", totalAPs/50);

  printf("proporción de muestras con 0 APs encontrados en las 50 repeticiones: %f % \n", ceroAPs*100/50);

  return 0;
}

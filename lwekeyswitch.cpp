#include "lwekeyswitch.h"


LWEKeySwitchKey::LWEKeySwitchKey(int base, LWEParams* in_params, LWEParams* out_params){
    this->base=base;
    this->in_params=in_params; 
    this->out_params=out_params; 
    int n=in_params->n;
    int l=5; // à faire, 5 c'est pas la bonne valeur
    ks0_raw = new_LWESample_array(n*l*base,out_params);
    ks1_raw = new LWESample*[n*l*base];
    ks2_raw = new LWESample**[n*l];
    ks = new LWESample***[n];

    for (int p = 0; p < n*l*base; ++p)
    	ks1_raw[p] = ks0_raw + p;
    for (int p = 0; p < n*l; ++p)
	    ks2_raw[p] = ks1_raw + base*p;
	 for (int p = 0; p < n; ++p)
	    ks[p] = ks2_raw + l*p;
}

LWEKeySwitchKey::~LWEKeySwitchKey() {
	delete_LWESample_array(in_params->n*l*base,ks0_raw);
    delete[] ks1_raw;
    delete[] ks2_raw;
    delete[] ks;
}


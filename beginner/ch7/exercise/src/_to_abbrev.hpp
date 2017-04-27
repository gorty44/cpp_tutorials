#ifndef _TO_ABBREV_HPP_
#define _TO_ABBREV_HPP_

#include <string>
#include "_model/_state_abbrev.hpp"

StateAbbrev to_abbrev(std::string state_name) {
	if (state_name == "Alabama")
		return StateAbbrev::AL;
	else if (state_name == "Alaska")
		return StateAbbrev::AK;
	else if (state_name == "Arizona")
		return StateAbbrev::AZ;
	else if (state_name == "Arkansas")
		return StateAbbrev::AR;
	else if (state_name == "California")
		return StateAbbrev::CA;
	else if (state_name == "Colorado")
		return StateAbbrev::CO;
	else if (state_name == "Connecticut")
		return StateAbbrev::CT;
	else if (state_name == "Delaware")
		return StateAbbrev::DE;
	else if (state_name == "Florida")
		return StateAbbrev::FL;
	else if (state_name == "Georgia")
		return StateAbbrev::GA;
	else if (state_name == "Hawaii")
		return StateAbbrev::HI;
	else if (state_name == "Idaho")
		return StateAbbrev::ID;
	else if (state_name == "Illinois")
		return StateAbbrev::IL;
	else if (state_name == "Indiana")
		return StateAbbrev::IN;
	else if (state_name == "Iowa")
		return StateAbbrev::IA;
	else if (state_name == "Kansas")
		return StateAbbrev::KS;
	else if (state_name == "Kentucky")
		return StateAbbrev::KY;
	else if (state_name == "Louisiana")
		return StateAbbrev::LA;
	else if (state_name == "Maine")
		return StateAbbrev::ME;
	else if (state_name == "Maryland")
		return StateAbbrev::MD;
	else if (state_name == "Massachusetts")
		return StateAbbrev::MA;
	else if (state_name == "Michigan")
		return StateAbbrev::MI;
	else if (state_name == "Minnesota")
		return StateAbbrev::MN;
	else if (state_name == "Mississippi")
		return StateAbbrev::MS;
	else if (state_name == "Missouri")
		return StateAbbrev::MO;
	else if (state_name == "Montana")
		return StateAbbrev::MT;
	else if (state_name == "Nebraska")
		return StateAbbrev::NE;
	else if (state_name == "Nevada")
		return StateAbbrev::NV;
	else if (state_name == "New Hampshire")
		return StateAbbrev::NH;
	else if (state_name == "New Jersey")
		return StateAbbrev::NJ;
	else if (state_name == "New Mexico")
		return StateAbbrev::NM;
	else if (state_name == "New York")
		return StateAbbrev::NY;
	else if (state_name == "North California")
		return StateAbbrev::NC;
	else if (state_name == "North Dakota")
		return StateAbbrev::ND;
	else if (state_name == "Ohio")
		return StateAbbrev::OH;
	else if (state_name == "Oklahoma")
		return StateAbbrev::OK;
	else if (state_name == "Oregon")
		return StateAbbrev::OR;
	else if (state_name == "Pennsylvania")
		return StateAbbrev::PA;
	else if (state_name == "Rhode Island")
		return StateAbbrev::RI;
	else if (state_name == "South Carolina")
		return StateAbbrev::SC;
	else if (state_name == "South Dakota")
		return StateAbbrev::SD;
	else if (state_name == "Tennessee")
		return StateAbbrev::TN;
	else if (state_name == "Texas")
		return StateAbbrev::TX;
	else if (state_name == "Utah")
		return StateAbbrev::UT;
	else if (state_name == "Vermont")
		return StateAbbrev::VT;
	else if (state_name == "Virginia")
		return StateAbbrev::VA;
	else if (state_name == "Washington")
		return StateAbbrev::WA;
	else if (state_name == "West Virginia")
		return StateAbbrev::WV;
	else if (state_name == "Wisconsin")
		return StateAbbrev::WI;
	else if (state_name == "Wyoming")
		return StateAbbrev::WY;
	else
		throw std::logic_error("Invalid state");
}

#endif // _TO_ABBREV_HPP_

	



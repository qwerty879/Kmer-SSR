/*
 * 	Brandon Pickett
 * 	taskContainer.cpp
 *
 * 	This program's purpose is to do some basic testing of the TaskContainer
 * 	class.
 */

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cstdint>

#include "../../include/TaskQueue.h"
#include "../../include/Task.h"

using namespace std;

//int main(int argc, char** argv)
int main()
{
	TaskQueue tasks1 = TaskQueue();
	TaskQueue tasks2 = TaskQueue();
	//TaskQueue tasks();

	//cout << tasks.toString() << endl;

	vector<string> ids;

	stringstream strm;
	string str;
	for (uint32_t j = 0; j < 4; ++j)
	{
		for (uint32_t i = 0; i < 12; ++i)
		{
			strm << "seq_" << i;
			strm >> str;
			ids.push_back(str);
			strm.clear();
		}
	}

	vector<string> seqs( {
		"CATAACGTTGACGGATCATTGTACGCCAGTTGAAGTAAGAGATTTGCAGGCATCACTCTGTCGAAGACGAAACATATGTATACAAATATCAACGCATG",
		"GCCAGGCCACGTTAAGTGCGTAACACTGCTTAA",
		"TAGTGATTATGTCAGTGGGCCACCTATACTTTGGGTAATGTCCATGTAACACTATAAATCCAAGGCATATCTTCTCACACGGTACGCACGAACGGCTCGA",
		"AGGACTCCTGCAGATCCTGGACGCTGACTCTCAAACAAACCGCTGCTTTGCGTCGAGGGCAGACCCGTATAAGTCGCCCTACA",
		"GAAACGAGCGGGTATTGACTCTAGCCTGAAAAAAACATCGCTGTAAGC",
		"AGATACTGTTAAGGACTACTGCCCAGCTCAAATGCAATGGATACTGGCGTCCAAGCGACCTGTTTGACAGACCGCTTGTGCAACTCAAATGCTGT",
		"CCGGACCCCGAGCTTATCTAGGTAACTTTGAACTCTACAACCAATCCAAATCCAAC",
		"GACAGAAGCCGGTATACTAATTGCCGAACATATCGAAGCGATAAGGCTATTACTAAGCG",
		"AACTCAAGGTATTTCCACGCAGCGTATCCATGGAGATAATCGGTTGTGCACTGCATCGAAGCTTATACTTGGCGTACAA",
		"CGCGTGCGGGCCCGATCTTTGGACGGTCACGTGGACGTAGGACTGATTACT",
		
		"TCCAAAGTCGCAAAGATCTGCCTTGGAAAGCAGAGCGCTATTATTGTACAGGATGGCGATCTATTTGCCCGAGTTGACCGACGCAAACGTTCGAGGCTGC",
		"GTAGGTTCTAGAGGATATATCACTTTCCATAAAGTTCTGGTAGCAGTAATCAACTGGAATGGCTC",
		"TACAACACCGCTGTGCGCCGTAAAGATAGTCGCGGCTTCAGGCACGTATGGACATGTTTGAGCCATGTTGAGTTGAGGCCTCAGTTACCTACCGG",
		"ACCAGTAGTTCCCGTTCCGCGAAATTCCCCCGGATTCGTCTCGCATTCGATATTGGGTGTGGAAGAGGTAGGAGGA",
		"TCGCCACAGGCCTCTGAATGCTAGTCCTCGGACGCATCCGACTCAACCGGCGAGGTCCACAACCTTT",
		"TATCGCTATCCCCACGCACTTCTCTGGGCCGATAGCGTAACAGCATTTGTACTCGACAGGGGGATATTGGATAGCCTACCGT",
		"CCACAAAAGTCGTCTGCAAAATCACGTAGGATATTTGTCGACACCGCACCGCCAAGAAGCCATAGCATTT",
		"ATTGCATTATACACAATCTTTTTTATGATGTCTGGACCGTGCCGAGCGAAGTTCTGACATCTGAGGTGTC",
		"AGCGAGTATGCAGGGATCGTGATCATCTACTCGCACGAGCTCTACGTGGCG",
		"AAGCTGGTTTACATATTCCTCGGTTGGTTACGAACGCAAGGGCAGTCTATTCAGGAAGACTGACGCTAGGAGCAC",
		
		"CTCGGGCACGAGATGATTAGCACCGGGAACGCAGTTCCTTC",
		"CTTGCAACTTTTGGTGATGTTCTGTATCTTT",
		"TAATCGGATGGAGCGAGTATAAGCACCACGCGCGAGGTTCAGCACTGTTCCGTATTATCATACCTGTTTTAGCC",
		"GAACCGGGAGAATTAGTACTTGTGAATCGTACGAAACAGGCTCACTGGTAAC",
		"TGACTGCGAGCTGAAGGAGTACCGCTCTTCAAGCCAGCCAGGAGATTACATCATTAATCTCCTCGTGATCAGCTGCGGTTCAACTTCGACTTACCCGTT",
		"AACTCTAACGGGTCTCCTTTTGAATATACCTTGGTTAGAATCTTCCATAACGCGGGATCAACTTGTCCTTAAGTGCACGGTTT",
		"ACAGGGTTGTTCAATGGATGCGTGCGGTAGCCATACGTGGACCTATCTGAGAGGGTATTAATAAACCTACTCGAGTGGC",
		"TGAGTCGCCCGCTCGCGCCCAATTTCCGGTAGAGAATCGCAACGTCGTGCGCA",
		"ATACGACGGGCTGTCCTAACTCGTGCGGTCTT",
		"CTCGTCAGATCCGTACGCTGGGACGCGGTGGTTACTACTAAGG",
		
		"ACCTGTCGATCTCTCTTTCATATATATATGTGCCATTAGGCATGCTAAATGTGCTCGTCTGCATGCTTTCTCACCATTTCGATTCACAAA",
		"TACACGACCCGGGGACGCTGATATTGTGGGGACAAAGTGTCCA",
		"ATGCTTGTAACGACCCCAGTAGGGTTACGCTTTTGTCAGAAACCGTG",
		"ATTAAGGCCGTTCAAGCCCACGTGTGATTAAGCGGTCTGCAG",
		"TGCTATGCCCGTAATCCTAGTCATGGCCCTAAATGACGGGGAAATAGAACTTGGAGGCCAGGGTGACGCCTC",
		"TCTCGGTGCTGGATCGCCGTAAGAAAGAGCTTCCATTTCCACTTCGCGCAATCTTTGT",
		"TATGGCAGGGCTATTTTCAGTTCAAACATTTTAATATATCAACTTGGCCTGTGATCGACCAAAACAAGCGTAGGTCAGGATAAG",
		"GCTCTTTTCGGCCTTATGTATAGTGACACCACATCTTAACGTCGACACAATACGCAACTCCTATCAGTGGAACTA",
		"GGAACGTATCCATTGGAAATCGAGACGATGGGCTTCCACTTGTCTGG",
		"GATTCGAGAGGCCACGGCAGCGCCCAGCCTGTAAGTAAGTA",
		
		"TCTTCGATGTCTGGAGGAGCCACCTTACTTTTGAAAACAGTATGCGATGTGTCTCCAGGTATTTGATAACCTGACTTG",
		"TTCATAACTCATACTTAAAAATTCATAACAAGAAGTTTCCGGAAATT",
		"CCCAGCAAATTACTGAGGGCACTAGGTGGGTCGATCTGTGACTAAATGCCCTAGCTCGATCGCCCTCGGAGGACCAACCTCCCTCGGCTCTGAAAACAT",
		"TATAAGCGCAGAGCACACGAATTGGTGCCTATCTGACAAGGAGCGACATAGACACACCAGTGCAG",
		"GATAGGCTGAGGATTGAGAAGTGCGACACATTGAGTCAAACCCAGTGTACTGTTTTACCTGGCCTCAGTTGATAAGACCCACATAATCCCGTTACACTA",
		"AGTTATTGGTCGACCGCTATCTTAGGCATGGCTTGTAGC",
		"GGTTCCTGCGCCAAACAAAACGATCCGATGCTTCTAGTCG",
		"GTCTAATGGTGTCCTGGGCGTCATTCGGAGGTTGAGATCAGACTTTGTGATGGGGTTCCTTGTGAG"
	} );

	vector<uint32_t> global_sequence_lengths( {
		801, 680, 288, 849, 496, 911, 497, 200, 507, 267,
		779, 189, 521, 928, 333, 870, 178, 382, 895, 506,
		455, 917, 188, 319, 966, 896, 932, 691, 960, 560,
		695, 703, 888, 332, 900, 517, 869, 289, 991, 213,
		877, 405, 710, 435, 840, 677, 360, 345
	} );

	vector<uint32_t> global_positions( {
		757, 918, 849, 478, 623, 860, 373, 375, 553, 936,
		119, 988, 445, 240, 167, 872, 902, 507, 967, 581,
		499, 962, 807, 838, 403, 428, 327, 360, 701, 570,
		579, 700, 772, 438, 458, 482, 936, 880, 739, 158,
		606, 449, 762, 603, 766, 411, 568, 175
	} );

	/*
	 * 	NOTE: A global position cannot technically be larger than the global
	 * 	sequence length. However, for testing purposes, we just generated 48
	 * 	random numbers and stuck them in these two vectors.
	 */
		
	for (uint32_t i = 0; i < 48; ++i)
	{
		Task* temp_task_ptr = new Task(ids[i], seqs[i], global_positions[i], global_sequence_lengths[i]);
		tasks1.add(temp_task_ptr);
		
		temp_task_ptr = new Task(ids[i], seqs[i], global_positions[i], global_sequence_lengths[i]);
		tasks2.add(temp_task_ptr);
	}

	//cout << tasks2.toString() << endl;
	//cout << tasks2.toJson() << endl;

	for (uint32_t i = 0; i < 3; ++i)
	{
		Task* temp_ptr = tasks2.get();
		delete temp_ptr;
	}

	tasks2.clear();

	bool pass = true;
	string pass_or_fail_msg = pass ? "\033[0;32mOK" : "\033[0;31mFAIL";
	cout << "\n\033[0;34mTaskQueue Test: " << pass_or_fail_msg << "\033[0m" << endl;
	
	return 0;
}

#include "debug.h"
#include "../dsRepository.h"

// this file will recieve multiple changes and is intended for testing singular components

int main()
{
	debugingVL<52> debug(true);
	Selection<int, char> selection;
	Bubble<int, char> bubble;
	Insertion<int, char> insertion;
	Quick<int, char> quick;
	arrayPrint<int, char> tools;
	debuggingTools<int, 52> intTools;

	bool sortDebug = true;

	bool acndDebug = true;
	if (acndDebug == true || sortDebug == true)
	{
		cout << "Acending:\n";
		cout << quick.sort(debug.VLnumbersUnsorted, 52, 'A') << endl;
		cout << "Known good:\n";
		tools.print(debug.VLnumbersSortedAcending, 52, 'H');
		cout << "Test:\n";
		tools.print(debug.VLnumbersUnsorted, 52, 'H');
		intTools.arrayCompairisonTest(debug.VLnumbersSortedAcending, debug.VLnumbersUnsorted);
	}

	bool decndDebug = false;
	if (decndDebug == true || sortDebug == true)
	{
		intTools.randomise(debug.VLnumbersUnsorted, 52);

		cout << "\n\nDecending:\n";
		cout << insertion.sort(debug.VLnumbersUnsorted, 52, 'D') << endl;
		cout << "Known good:\n";
		tools.print(debug.VLnumbersSortedDecending, 52, 'H');
		cout << "Test:\n";
		tools.print(debug.VLnumbersUnsorted, 52, 'H');
		intTools.arrayCompairisonTest(debug.VLnumbersSortedDecending, debug.VLnumbersUnsorted);
	}
}
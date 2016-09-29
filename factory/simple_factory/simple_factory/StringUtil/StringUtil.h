#pragma once
#include <string>
#include <vector>
#include <algorithm>
using std::string;
using std::vector;


/** \addtogroup Core
*  @{
*/
/** \addtogroup General
*  @{
*/

/** Utility class for manipulating Strings.  */
class StringUtil
{
public:

	/** Removes any whitespace characters, be it standard space or
		TABs and so on.
		@remarks
			The user may specify wether they want to trim only the
			beginning or the end of the string ( the default action is
			to trim both).
	*/
	static void trim( string& str, bool left = true, bool right = true );

	/** Returns a vector<string> that contains all the substrings delimited
		by the characters in the passed <code>delims</code> argument.
		@param
			delims A list of delimiter characters to split by
		@param
			maxSplits The maximum number of splits to perform (0 for unlimited splits). If this
			parameters is > 0, the splitting process will stop after this many splits, left to right.
		@param
			preserveDelims Flag to determine if delimiters should be saved as substrings
	*/
	static vector<string> split( const string& str, const string& delims = "\t\n ", unsigned int maxSplits = 0, bool preserveDelims = false);

	/** Returns a vector<string> that contains all the substrings delimited
		by the characters in the passed <code>delims</code> argument, 
		or in the <code>doubleDelims</code> argument, which is used to include (normal) 
		delimeters in the tokenised string. For example, "strings like this".
		@param
			delims A list of delimiter characters to split by
		@param
			delims A list of double delimeters characters to tokenise by
		@param
			maxSplits The maximum number of splits to perform (0 for unlimited splits). If this
			parameters is > 0, the splitting process will stop after this many splits, left to right.
	*/
	static vector<string> tokenise( const string& str, const string& delims = "\t\n ", const string& doubleDelims = "\"", unsigned int maxSplits = 0);

	/** Lower-cases all the characters in the string.
	*/
	static void toLowerCase( string& str );

	/** Upper-cases all the characters in the string.
	*/
	static void toUpperCase( string& str );


	/** Returns whether the string begins with the pattern passed in.
	@param pattern The pattern to compare with.
	@param lowerCase If true, the start of the string will be lower cased before
		comparison, pattern should also be in lower case.
	*/
	static bool startsWith(const string& str, const string& pattern, bool lowerCase = true);

	/** Returns whether the string ends with the pattern passed in.
	@param pattern The pattern to compare with.
	@param lowerCase If true, the end of the string will be lower cased before
		comparison, pattern should also be in lower case.
	*/
	static bool endsWith(const string& str, const string& pattern, bool lowerCase = true);

	/** Method for standardising paths - use forward slashes only, end with slash.
	*/
	static string standardisePath( const string &init);
	/** Returns a normalized version of a file path
	This method can be used to make file path strings which point to the same directory  
	but have different texts to be normalized to the same text. The function:
	- Transforms all backward slashes to forward slashes.
	- Removes repeating slashes.
	- Removes initial slashes from the beginning of the path.
	- Removes ".\" and "..\" meta directories.
	- Sets all characters to lowercase (if requested)
	@param init The file path to normalize.
	@param makeLowerCase If true, transforms all characters in the string to lowercase.
	*/
   static string normalizeFilePath(const string& init, bool makeLowerCase = true);


	/** Method for splitting a fully qualified filename into the base name
		and path.
	@remarks
		Path is standardised as in standardisePath
	*/
	static void splitFilename(const string& qualifiedName,
		string& outBasename, string& outPath);

	/** Method for splitting a fully qualified filename into the base name,
	extension and path.
	@remarks
	Path is standardised as in standardisePath
	*/
	static void splitFullFilename(const string& qualifiedName, 
		string& outBasename, string& outExtention, 
		string& outPath);

	/** Method for splitting a filename into the base name
	and extension.
	*/
	static void splitBaseFilename(const string& fullName, 
		string& outBasename, string& outExtention);


	/** Simple pattern-matching routine allowing a wildcard pattern.
	@param str string to test
	@param pattern Pattern to match against; can include simple '*' wildcards
	@param caseSensitive Whether the match is case sensitive or not
	*/
	static bool match(const string& str, const string& pattern, bool caseSensitive = true);


	/** replace all instances of a sub-string with a another sub-string.
	@param source Source string
	@param replaceWhat Sub-string to find and replace
	@param replaceWithWhat Sub-string to replace with (the new sub-string)
	@returns An updated string with the sub-string replaced
	*/
	static const string replaceAll(const string& source, const string& replaceWhat, const string& replaceWithWhat);

	/// Constant blank string, useful for returning by ref where local does not exist
	static const string BLANK;
};
/** @} */
/** @} */
#include <iostream>
#include <FL/Fl.H>
#include <FL/Fl_Browser.H>

int main()
{
Fl_Browser browser(10,10,500,500,"Test");

// CLEAR BROWSER
browser.clear();

// ADD LINES TO BROWSER
browser.add("One");            // fltk does strdup() internally       
browser.add("Two");
browser.add("Three");

// FORMAT CHARACTERS: CHANGING TEXT COLORS IN LINES
//    Warning: format chars are also returned back to you via ::text()
//    @C# - text color             @b  - bold
//    @B# - background color       @i  - italic
//    @F# - set font number        @f  - fixed pitch font
//    @S# - set point size         @u  - underline
//    @.  - terminate '@' parser   @-  - strikeout
//
browser.add("Black @C1Red @C2Green @C3Yellow");

// DISABLING FORMAT CHARACTERS
browser.format_char(0);

// ACCESS ALL SELECTED ITEMS IN BROWSER
// Note: browser's text() array is 1 based..!
//
for ( int t=1; t<=browser.size(); t++ ) {
    if ( browser.selected(t) ) {
        printf("%d) '%s'\n", t, browser.text(t));
    }
}

// PRE-SELECT ALL LINES IN BROWSER
//   Note: index numbers are 1 based..!
//
for ( int t=1; t<=browser.size(); t++ ) {
    browser.select(t);
}

// DE-SELECT ALL LINES IN BROWSER
browser.deselect();

// GET SINGLE SELECTED ITEM FROM BROWSER
int index = browser.value();

// USING INDEX NUMBER, RETURN TEXT
//   Note: index numbers are 1 based..!
//
if ( index > 0 ) {
    const char *s = browser.text(index);
    std::cout << "and so on...\n";
}

//browser.show();//does not help
 std::cout << "Nothing happens, mere code illustration.\n";

return Fl::run(); 
}

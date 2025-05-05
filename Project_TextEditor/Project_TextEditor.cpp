#include <iostream>
#include <string>
#include <stack>

//abstract
class TextAction {
protected:
	size_t start;
	size_t end;
	std::string actionName;
public:
	std::string textBeforeAction;
	std::string textAfterAction;

	//constr & destr
	TextAction(size_t start, size_t end, const std::string& actionName)
		: start(start), end(end), actionName(actionName) {
	}
	virtual ~TextAction() = default;

	//pure vm
	virtual std::string PerformAction(const std::string& OriginalText) = 0; 

	//return method
	std::string UndoAction() {
		return textBeforeAction;
	};
};


//bold
class BoldAction : public TextAction {
public:
	BoldAction(size_t start, size_t end)
		: TextAction(start, end, "Bold") {
	}

	std::string PerformAction(const std::string& OriginalText) override {
		textBeforeAction = OriginalText;

		std::string inserted = OriginalText;
		inserted.insert(start, "<b>");
		inserted.insert(end + 3, "</b>");

		textAfterAction = inserted;
		return inserted;
	}
};
//italic
class ItalicAction : public TextAction {
public:
	ItalicAction(size_t start, size_t end)
		: TextAction(start, end, "Italic") {
	}

	std::string PerformAction(const std::string& OriginalText) override {
		textBeforeAction = OriginalText;

		std::string inserted = OriginalText;
		inserted.insert(start + 3, "<i>"); 
		inserted.insert(end + 6, "</i>");  

		textAfterAction = inserted;
		return inserted;
	}
};
//color
class ColorAction : public TextAction {
public:
	ColorAction(size_t start, size_t end)
		: TextAction(start, end, "Color") {
	}

	std::string PerformAction(const std::string& OriginalText) override {
		textBeforeAction = OriginalText;

		std::string inserted = OriginalText;
		inserted.insert(start, "<Color=red>");
		inserted.insert(end + 11, "</Color>");

		textAfterAction = inserted;
		return inserted;
	}
};

//editor
class TextEditor {
protected:
	std::string Text;
	std::stack <TextAction*> History;
public:
	TextEditor() : Text("") {}
	~TextEditor() { //deleting but if not empty
		while (!History.empty()) {
			delete History.top();
			History.pop();
		}
	}

	//applying
	void ApplyAction(TextAction* action) {
		Text = action->PerformAction(Text);
		History.push(action); //pushing action into stack
	}

	//undo finish
	void Undo() {
		if (History.empty()) return;
		//accessing last action
		TextAction* lastAction = History.top();
		//deleting last action
		Text = lastAction->UndoAction();
		delete lastAction;
		History.pop();  //at First I forgot to put POP and the program would crash on Undo color because of too long string :) (for me)
	}

	const std::string& GetText() const { return Text; } //to return text otherwise wouldn't work in Main
	std::string& TextFromEditor = Text; // new variable otherwise Text variable from protected is not accessible in the MAIN function
};
int main()
{
	TextEditor editor;
	editor.TextFromEditor = "This is a test sentence.";

	std::cout << "Original Text: " << editor.GetText() << std::endl;

	editor.ApplyAction(new BoldAction(10, 14));
	std::cout << "After Bold: " << editor.GetText() << std::endl;
	editor.ApplyAction(new ItalicAction(19, 27));
	std::cout << "After Italic: " << editor.GetText() << std::endl;
	editor.ApplyAction(new ColorAction(0, 4));
	std::cout << "After Color: " << editor.GetText() << std::endl;

	editor.Undo();
	std::cout << "After Undo (Color): " << editor.GetText() << std::endl;
	editor.Undo();
	std::cout << "After Undo (Italic): " << editor.GetText() << std::endl;
	editor.Undo();
	std::cout << "After Undo (Bold): " << editor.GetText() << std::endl;

	return 0;
}

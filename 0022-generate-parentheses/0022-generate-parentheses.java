import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> result = new ArrayList<>();
        // Using StringBuilder is much more efficient than regular String concatenation in Java
        StringBuilder currentString = new StringBuilder();
        backtrack(result, currentString, 0, 0, n);
        return result;
    }

    private void backtrack(List<String> result, StringBuilder currentString, int openCount, int closeCount, int maxPairs) {
        // Base case: if the string reaches the required length (2 * n)
        if (currentString.length() == 2 * maxPairs) {
            result.add(currentString.toString());
            return;
        }

        // Rule 1: Add an open parenthesis if we haven't reached the limit 'n'
        if (openCount < maxPairs) {
            currentString.append('(');
            backtrack(result, currentString, openCount + 1, closeCount, maxPairs);
            currentString.deleteCharAt(currentString.length() - 1); // Backtrack step
        }

        // Rule 2: Add a close parenthesis if it matches a previously opened one
        if (closeCount < openCount) {
            currentString.append(')');
            backtrack(result, currentString, openCount, closeCount + 1, maxPairs);
            currentString.deleteCharAt(currentString.length() - 1); // Backtrack step
        }
    }
}

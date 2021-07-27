/**
 * HangMan Game Implemented in Java
 * Copyright 2018, Ajith Ramachandran, ajithar204@gmail.com
 *
 * This software is released under the terms of the
 * GNU LGPL license. See http://www.gnu.org/licenses/lgpl.html
 * for more information.
 *
 * */

import java.util.*;
import static java.lang.System.exit;

public class HangMan {
    private Random rand = new Random();
    private Scanner reader = new Scanner(System.in);

    private String[] wordList = {"asphyxiation", "justice", "death", "fading", "punishment", "sentence", "execution", "unjust",
            "struggle", "throat", "trachea", "breathing", "oxygen", "gasping", "suffering", "spectators", "gallows", "powerless"};
    private int wordLength = wordList.length, wordIndex = rand.nextInt(wordLength), numberFails = 5, number = 0, correctInstances = 0;
    private String word = wordList[wordIndex];

    private String[] keys = new String[12];

    private String[] toStringArray(String word) {
        String[] array = new String[wordLength];
        for (int i = 0; i < word.length(); i++){
            char c = word.charAt(i);
            array[i] = (String.valueOf(c));
        }
        return array;
    }

    private List<String> toStringList(String word) {
        List<String> array = new ArrayList<>();
        for (int i = 0; i < word.length(); i++){
            char c = word.charAt(i);
            array.add(String.valueOf(c));
        }
        return array;
    }


    private boolean checkWin(String[] solution) {
        List<String> wordArray = toStringList(word);
        List<String> solution_ = Arrays.asList(solution);
        if(solution_.equals(wordArray))
            return true;
        return false;
    }


    private ArrayList<Integer> check(String key) {
        ArrayList<Integer> charArray = new ArrayList<>();
        if (!word.contains(key)) {
            return charArray;
        } else {
            String[] wordArray = toStringArray(word);
            for(int i = 0; i< word.length(); i++) {
                if (wordArray[i].equals(key)) {
                    charArray.add(i);
                }
            }
            return charArray;
        }
    }

    private void print(String[] solution){
        for (String s : solution) System.out.print(s + " ");
        System.out.println(" ");
    }

    private void hangMan(){
        System.out.println(word);
        String[] solution = new String[word.length()];
        for(int i=0; i<word.length(); i++)
            solution[i] = "-";
        print(solution);
        while (true) {
            String key = reader.nextLine();
            if(key.length() > 1)
                System.out.println("Enter Only One character!");
            ArrayList<Integer> charList;
            charList = check(key);
            if(Arrays.asList(keys).contains(key))
                System.out.println("Already Entered");
            if (check(key).isEmpty()) {
                System.out.println("oops that's a fail!");
                print(solution);
                numberFails--;
                if(numberFails == 0){
                    System.out.println("You Lose!");
                    System.out.println(word);
                    exit(0);
                }
            } else {
                keys[number] = key;
                number++;
                for (int i: charList)
                    solution[i] = key;
                correctInstances++;
                if(checkWin(solution)){
                    System.out.println("You Won!");
                    print(solution);
                    exit(0);
                }
                print(solution);
            }
        }
    }

    public static void main(String[] args) {
        HangMan hangMan = new HangMan();
        hangMan.hangMan();
    }
}

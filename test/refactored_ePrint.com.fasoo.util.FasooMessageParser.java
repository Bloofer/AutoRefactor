/*
 * IMPORTANT INFORMATION: This file and all portions of it are Customizable
 * Technology and may be modified or changed consistent with the terms and
 * conditions of your license agreement with Fasoo.com.
 * 
 * Use of this file and any portion of it, and all derivatives of this file or
 * any portion, are governed by your license agreement with Fasoo.com.
 * Copyright(c) 2003 Fasoo.com All rights reserved. This notice must be included
 * in all copies (or derivatives) of this file.
 */
package com.fasoo.util;

import java.util.*;

public class FasooMessageParser
{


    public Hashtable parse(String s)
    {
        String valArray[] = null;
        if (s == null) throw new IllegalArgumentException();

        Hashtable ht = new Hashtable();
        StringBuffer sb = new StringBuffer();
        String key;

        for (StringTokenizer st = new StringTokenizer(s, "&"); st.hasMoreTokens(); ht.put(key, valArray))
        {
            String pair = st.nextToken();
            int pos = pair.indexOf(61);
            if (pos == -1) throw new IllegalArgumentException();

            key = pair.substring(0, pos);
            String val = parseName(pair.substring(pos + 1, pair.length()), sb);

            if (ht.containsKey(key))
            {
                String oldVals[] = (String[]) ht.get(key);
                valArray = new String[oldVals.length + 1];
                for (int i = 0; i < oldVals.length; i++)
                    valArray[i] = oldVals[i];

                valArray[oldVals.length] = val;
            }
            else
            {
                valArray = new String[1];
                valArray[0] = val;
            }
        }

        return ht;
    }


//     public Hashtable parse2(String s)
//     {
//         String valArray[] = null;
//         if (s == null) throw new IllegalArgumentException();
// 
//         Hashtable ht = new Hashtable();
//         StringBuffer sb = new StringBuffer();
//         String key;
// 
//         for (StringTokenizer st = new StringTokenizer(s, "&"); st.hasMoreTokens(); ht.put(key, valArray))
//         {
//             String pair = st.nextToken();
//             int pos = pair.indexOf(61);
//             if (pos == -1) throw new IllegalArgumentException();
// 
//             key = pair.substring(0, pos);
//             String val = parseName2(pair.substring(pos + 1, pair.length()), sb);
// 
//             if (ht.containsKey(key))
//             {
//                 String oldVals[] = (String[]) ht.get(key);
//                 valArray = new String[oldVals.length + 1];
//                 for (int i = 0; i < oldVals.length; i++)
//                     valArray[i] = oldVals[i];
// 
//                 valArray[oldVals.length] = val;
//             }
//             else
//             {
//                 valArray = new String[1];
//                 valArray[0] = val;
//             }
//         }
// 
//         return ht;
//     }


    byte messageHexInt(byte x)
    {
        return (x >= '0' && x <= '9') ? (byte) (x - '0') : (x >= 'a' && x <= 'f') ? (byte) (x - 'a' + 10)
                : (x >= 'A' && x <= 'F') ? (byte) (x - 'A' + 10) : (byte) 0;
    }


    private String parseName(String s, StringBuffer sb)
    {

        sb.setLength(0);
        for (int i = 0; i < s.length(); i++)
        {
            char c = s.charAt(i);
            switch (c)
            {
                case 43: // '+'
                    sb.append(' ');
                    break;

                case 37: // '%'
                    try
                    {
                        sb.append((char) Integer.parseInt(s.substring(i + 1, i + 3), 16));
                        i += 2;
                        break;
                    }
                    catch (NumberFormatException e)
                    {
                        throw new IllegalArgumentException();
                    }
                    catch (StringIndexOutOfBoundsException e)
                    {
                        String rest = s.substring(i);
                        sb.append(rest);
                        if (rest.length() == 2) i++;
                    }
                    break;

                default:
                    sb.append(c);
                    break;

            }
        }
        return sb.toString();
    }


    private String parseName2(String s, StringBuffer sb)
    {
        return s;
    }
}

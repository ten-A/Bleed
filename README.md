# Bleed
This is a sample project of how to use Adobe Illustrator SDKs SendScriptMessage interface for Macintosh(Xcode).

You can push this Plugin from ExtendScript and set a document bleeds.  
Ex:  
>alert(setBleed(36)); //unit = pt  
>  
>function setBleed(n){  
>   var result = app.sendScriptMessage('Bleed', 'Bleed', n);  
>   return result;  
>   }

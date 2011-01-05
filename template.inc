<?php


class mainTemplate extends template {

/**
 * method for printing out template header
 *
 * @param  array    assoc array containing current page info
 */
public static function printHeader(){ ?>
<!doctype html>
<html lang="<?=register::$vars['coscms_main']['lang']?>">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title><?php echo $_SERVER['HTTP_HOST']?> :: <?php echo template::getTitle(); ?></title>

<?php

echo template::$meta;

//$db = new db();
//$row = $db->selectOne('settings', 'id', 1);

if (isset(register::$vars['coscms_main']['css'])){
// if (isset($row['css']) && $row['css'] != ''){
    $css = register::$vars['coscms_main']['css'];
    template::setCss("/templates/zimpleza/$css");
} else {
    template::setCss("/templates/zimpleza/common4.css");
}


template::setCss('/templates/zimpleza/highlight.css');

echo template::getCss();
echo template::getInlineCss();

template::setJs("http://ajax.googleapis.com/ajax/libs/jquery/1.4.2/jquery.min.js", 10);
template::setJs("http://ajax.googleapis.com/ajax/libs/jqueryui/1.8.4/jquery-ui.js", 20);

echo template::getJs();
echo template::getInlineJs();


?>


</head>
<body>
<div id="page">
    <div id="header">
        <?php if (empty(register::$vars['coscms_main']['logo'])) { ?>
            <div id ="logo_title"><h3><a href="/"><?php echo $_SERVER['HTTP_HOST']?></a></h3></div><?php
        } else { ?>
            <div id = "logo_img"><a href="/"><img alt="<?php echo $_SERVER['HTTP_HOST']?>" src="/logo/<?=register::$vars['coscms_main']['logo']?>" /></a></div><?php
        } ?>
        
    </div>
    <div id="sidebar_left">
<?php

$blocks = layout::getBlocks();
foreach ($blocks as $key => $val){
    print $val;
}

?>
    </div>
    <div id="sidebar_right">
<?php

$blocks_sec = layout::getBlocksSec();
foreach ($blocks_sec as $key => $val){
      print $val;
}


?>
   </div>
    <div id="content">
        <div id="main_menu"><?php
echo layout::getMainMenu();

?>

        </div>
        <div id="module_menu">
<?php

echo layout::getModuleMenu();

?>
        </div>
        <div id="system_message"><p>
<?php

echo session::getActionMessage();

?>
        </p></div>
<?php

// content of loaded module will be printed

}

/**
 * method for print footer of page
 */
public static function printFooter(){

?>
        <div id="end_content">
<?php

echo template::getEndContent();

?>
            <p style="text-align:center;">
<?php

echo register::$vars['coscms_main']['footer_message'];

?>
</p>
        </div>
    </div>
    <div id="footer">
    
    </div>
</div>
<?php

echo template::getEndHTML();

?>
</body>
</html>
<?php

}
    
// end of class 
}

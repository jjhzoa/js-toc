<?php

/**
 * function to create a easy TOC for any module. 
 * @param array $options array ('exclude' => 'h1', 'content' => '#content_article'); 
 */
function jstoc_set_toc ($options = array ()) {
    template::setJs('/templates/js-toc/jquery.toc-1.1.4.js');
    template::setCss('/templates/js-toc/toc.css');
    if (!isset($options['exclude'])) {
        $options['exclude'] = 'h1';
    }
    if (!isset($options['context'])) {
        $options['context'] = '#content';
    }
    $str = <<<EOF
$(document).ready(function() {
    $('#toc').toc({exclude: '{$options['exclude']}' , context: '{$options['context']}', autoId: true});
});
EOF;


    template::setStringJs($str);
}

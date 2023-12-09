#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "ast.h"

const char *dom_tokens[] = {
    "Document",
    "TextElement",
    "Paragraph",
    "Bold",
    "Italic",
    "Underline",
    "Strikethrough",
    "Header1",
    "Header2",
    "Header3",
    "Header4",
    "Header5",
    "Header6",
    "Quote",
    "Link",
    "Image",
    "InlineCode",
    "BlockCode",
    "HRule",
    "SVG"
};

const char *svg_tokens[] = {
    "Line",
    "Polyline",
    "Polygon",
    "Circle",
    "Ellipse",
    "Rect",
    "Text"
};


void print_error(const char* function, const char* str, ...) {
    va_list argptr;

    va_start(argptr, str);
    printf("[ERROR] For function %s: ", function);
    vfprintf(stdout, str, argptr);
    printf("\n");
    va_end(argptr);
}

int main(void) {
    SvgCoord *coords = new_svg_coord(50, 15);

    if (coords == NULL) {
        print_error("new_svg_coord", "The coordinates object is NULL!");
    }
    if (coords != NULL && coords->x != 50) {
        print_error("new_svg_coord", "The coordinate X should be 50, get: %d", coords->x);
    }
    if (coords != NULL && coords->y != 15) {
        print_error("new_svg_coord", "The coordinate Y should be 15, get: %d", coords->y);
    }

    SvgCoordList *coords_list = new_svg_coord_list(coords);

    if (coords_list == NULL) {
        print_error("new_svg_coord_list", "The coordinates list is NULL!");
    }
    if (coords_list != NULL && (coords_list->coord == NULL || coords_list->coord != coords)) {
        print_error("new_svg_coord_list", "The coordinates list should have the previous coordinates as element");
    }
    if (coords_list != NULL && coords_list->next != NULL) {
        print_error("new_svg_coord_list", "The coordinates list next element should be NULL");
    }

    SvgInst *svg_instruction = new_svg_inst(Circle, coords_list);

    if (svg_instruction == NULL) {
        print_error("new_svg_inst", "The svg instruction object is NULL!");
    }
    if (svg_instruction != NULL && svg_instruction->kind != Circle) {
        print_error("new_svg_inst", "The svg instruction kind should be Circle, get: %s", svg_tokens[svg_instruction->kind]);
    }
    if (svg_instruction != NULL && svg_instruction->coords != coords_list) {
        print_error("new_svg_inst", "The svg instruction coords should be the previous coordinates list");
    }
    if (svg_instruction != NULL && svg_instruction->width != -1) {
        print_error("new_svg_inst", "The svg instruction width should be -1 by default, get %d", svg_instruction->width);
    }
    if (svg_instruction != NULL && svg_instruction->height != -1) {
        print_error("new_svg_inst", "The svg instruction height should be -1 by default, get %d", svg_instruction->height);
    }
    if (svg_instruction != NULL && svg_instruction->text != NULL) {
        print_error("new_svg_inst", "The svg instruction text should be NULL by default, get %s", svg_instruction->text);
    }
    if (svg_instruction != NULL && svg_instruction->anchor != NULL) {
        print_error("new_svg_inst", "The svg instruction anchor should be NULL by default, get %s", svg_instruction->anchor);
    }
    if (svg_instruction != NULL && svg_instruction->color_stroke != NULL) {
        print_error("new_svg_inst", "The svg instruction color_stroke should be NULL by default, get %s", svg_instruction->color_stroke);
    }
    if (svg_instruction != NULL && svg_instruction->color_fill != NULL) {
        print_error("new_svg_inst", "The svg instruction color_fill should be NULL by default, get %s", svg_instruction->color_fill);
    }

    SvgList *svg_list = new_svg_list(svg_instruction);

    if (svg_list == NULL) {
        print_error("new_svg_list", "The svg instructions list object is NULL!");
    }
    if (svg_list != NULL && svg_list->svg != svg_instruction) {
        print_error("new_svg_list", "The svg instructions list first element should be the previous svg instruction");
    }
    if (svg_list != NULL && svg_list->next != NULL) {
        print_error("new_svg_list", "The svg instructions list next element should be NULL");
    }

    DOM *dom = new_dom(Paragraph, NULL);

    if (dom == NULL) {
        print_error("new_dom", "The dom object is NULL!");
    }
    if (dom != NULL && dom->dom_el != Paragraph) {
        print_error("new_dom", "The dom element should be Paragraph, get: %s", dom_tokens[dom->dom_el]);
    }
    if (dom != NULL && dom->children != NULL) {
        print_error("new_dom", "The dom children should be NULL!");
    }
    if (dom != NULL && dom->svg_children != NULL) {
        print_error("new_dom", "The dom svg children should be NULL!");
    }
    if (dom != NULL && dom->text != NULL) {
        print_error("new_dom", "The dom text should be NULL by default, get %s", dom->text);
    }
    if (dom != NULL && dom->url != NULL) {
        print_error("new_dom", "The dom url should be NULL by default, get %s", dom->url);
    }

    DomList *dom_list = new_dom_list(dom);

    if (dom_list == NULL) {
        print_error("new_dom_list", "The dom list object is NULL!");
    }
    if (dom_list != NULL && dom_list->dom != dom) {
        print_error("new_dom_list", "The dom list first element should be the previous dom");
    }
    if (dom_list != NULL && dom_list->next != NULL) {
        print_error("new_dom_list", "The dom list next element should be NULL");
    }
}

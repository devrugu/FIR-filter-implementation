#include "../pbplots/pbPlots.h"
#include "../pbplots/supportLib.h"

int orijinal_sinyal_ciz(uint32_t ornek_sayisi, double *sinyal)
{
    double xs[ornek_sayisi];

    for (uint32_t i = 0; i < ornek_sayisi; i++)
        xs[i] = i;

    _Bool success;
	StringReference *errorMessage;

	ScatterPlotSeries *series = GetDefaultScatterPlotSeriesSettings();
	series->xs = xs;
	series->xsLength = ornek_sayisi;
	series->ys = sinyal;
	series->ysLength = ornek_sayisi;
	series->linearInterpolation = true;
    //series->pointType = L"dotlinetoxaxis";
	//series->pointTypeLength = wcslen(series->pointType);
	//series->lineType = L"dotted";                             //grafiği noktalı yapmak için yorumdan çıkar
	//series->lineTypeLength = wcslen(series->lineType);
	series->color = CreateRGBColor(0, 0, 0);

	ScatterPlotSettings *settings = GetDefaultScatterPlotSettings();
	settings->width = 1280;
	settings->height = 720;
	settings->autoBoundaries = true;
	settings->autoPadding = true;
	settings->title = L"ORIJINAL SINYAL";
	settings->titleLength = wcslen(settings->title);
	settings->xLabel = L"ZAMAN";
	settings->xLabelLength = wcslen(settings->xLabel);
	settings->yLabel = L"GENLIK";
	settings->yLabelLength = wcslen(settings->yLabel);
	ScatterPlotSeries *s [] = {series};
	settings->scatterPlotSeries = s;
	settings->scatterPlotSeriesLength = 1;

	RGBABitmapImageReference *canvasReference = CreateRGBABitmapImageReference();
	errorMessage = (StringReference *)malloc(sizeof(StringReference));
	success = DrawScatterPlotFromSettings(canvasReference, settings, errorMessage);

	if(success){
		size_t length;
		double *pngdata = ConvertToPNG(&length, canvasReference->image);
		WriteToFile(pngdata, length, "orijinal_sinyal.png");
		DeleteImage(canvasReference->image);
	}else{
		fprintf(stderr, "Error: ");
		for(int i = 0; i < errorMessage->stringLength; i++){
			fprintf(stderr, "%c", errorMessage->string[i]);
		}
		fprintf(stderr, "\n");
	}

	return success ? 0 : 1;
}

int filtrelenmis_sinyal_ciz(uint32_t ornek_sayisi, double *sinyal)
{
    double xs[ornek_sayisi];

    for (uint32_t i = 0; i < ornek_sayisi; i++)
        xs[i] = (double)i;

    _Bool success;
	StringReference *errorMessage;

	ScatterPlotSeries *series = GetDefaultScatterPlotSeriesSettings();
	series->xs = xs;
	series->xsLength = ornek_sayisi;
	series->ys = sinyal;
	series->ysLength = ornek_sayisi;
	series->linearInterpolation = true;
    //series->pointType = L"dotlinetoxaxis";
	//series->pointTypeLength = wcslen(series->pointType);
	//series->lineType = L"dotted";                             //grafiği noktalı yapmak için yorumdan çıkar
	//series->lineTypeLength = wcslen(series->lineType);
	series->color = CreateRGBColor(0, 0, 0);


	ScatterPlotSettings *settings = GetDefaultScatterPlotSettings();
	settings->width = 1280;
	settings->height = 720;
	settings->autoBoundaries = true;
	settings->autoPadding = true;
	settings->title = L"FILTRELENMIS SINYAL";
	settings->titleLength = wcslen(settings->title);
	settings->xLabel = L"ZAMAN";
	settings->xLabelLength = wcslen(settings->xLabel);
	settings->yLabel = L"GENLIK";
	settings->yLabelLength = wcslen(settings->yLabel);
	ScatterPlotSeries *s [] = {series};
	settings->scatterPlotSeries = s;
	settings->scatterPlotSeriesLength = 1;

	RGBABitmapImageReference *canvasReference = CreateRGBABitmapImageReference();
	errorMessage = (StringReference *)malloc(sizeof(StringReference));
	success = DrawScatterPlotFromSettings(canvasReference, settings, errorMessage);

	if(success){
		size_t length;
		double *pngdata = ConvertToPNG(&length, canvasReference->image);
		WriteToFile(pngdata, length, "filtrelenmis_sinyal.png");
		DeleteImage(canvasReference->image);
	}else{
		fprintf(stderr, "Error: ");
		for(int i = 0; i < errorMessage->stringLength; i++){
			fprintf(stderr, "%c", errorMessage->string[i]);
		}
		fprintf(stderr, "\n");
	}

	return success ? 0 : 1;
}

int filtreyi_ciz(uint32_t ornek_sayisi, double *sinyal)
{
    double xs[ornek_sayisi];

    for (uint32_t i = 0; i < ornek_sayisi; i++)
        xs[i] = (double)i;

    _Bool success;
	StringReference *errorMessage;

	ScatterPlotSeries *series = GetDefaultScatterPlotSeriesSettings();
	series->xs = xs;
	series->xsLength = ornek_sayisi;
	series->ys = sinyal;
	series->ysLength = ornek_sayisi;
	series->linearInterpolation = true;
    //series->pointType = L"dotlinetoxaxis";
	//series->pointTypeLength = wcslen(series->pointType);
	//series->lineType = L"dotted";                             //grafiği noktalı yapmak için yorumdan çıkar
	//series->lineTypeLength = wcslen(series->lineType);
	series->color = CreateRGBColor(0, 0, 0);


	ScatterPlotSettings *settings = GetDefaultScatterPlotSettings();
	settings->width = 1280;
	settings->height = 720;
	settings->autoBoundaries = true;
	settings->autoPadding = true;
	settings->title = L"FILTRE";
	settings->titleLength = wcslen(settings->title);
	settings->xLabel = L"ZAMAN";
	settings->xLabelLength = wcslen(settings->xLabel);
	settings->yLabel = L"GENLIK";
	settings->yLabelLength = wcslen(settings->yLabel);
	ScatterPlotSeries *s [] = {series};
	settings->scatterPlotSeries = s;
	settings->scatterPlotSeriesLength = 1;

	RGBABitmapImageReference *canvasReference = CreateRGBABitmapImageReference();
	errorMessage = (StringReference *)malloc(sizeof(StringReference));
	success = DrawScatterPlotFromSettings(canvasReference, settings, errorMessage);

	if(success){
		size_t length;
		double *pngdata = ConvertToPNG(&length, canvasReference->image);
		WriteToFile(pngdata, length, "filtre4.png");
		DeleteImage(canvasReference->image);
	}else{
		fprintf(stderr, "Error: ");
		for(int i = 0; i < errorMessage->stringLength; i++){
			fprintf(stderr, "%c", errorMessage->string[i]);
		}
		fprintf(stderr, "\n");
	}

	return success ? 0 : 1;
}